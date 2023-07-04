#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 1e15 + 7;

template<typename T>
void debug(T &arr){
    for(ll elem : arr){
        cerr << elem << ' ';
    }
    cerr << '\n';
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    ll altsum = 0;
    ll l = 0;
    ll r = INF;
    for(int i = 1; i < n; ++i){
        if(i & 1){
            altsum += a[i];
        }else{
            altsum -= a[i];
        }

        if(i & 1){
            r = min(r, altsum);
        }else{
            l = max(l, altsum);
        }
    }
    bool flag = false;

    if(l <= r){
        if(n & 1){
            ll b = a[0] + altsum;
            if(!(b & 1)){
                b >>= 1;
                if((l <= b) && (b <= r)){
                    flag = true;
                }
            }
        }else{
            if(a[0] == altsum){
                flag = true;
            }
        }
    }

    if(flag){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
