#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b = a;
    for(int i = n - 1; i > 0; --i){
        b[i] -= b[i - 1];
    }
    b[0] = 0;
    auto check = [&](ll t){
        int cnt = 0;
        t <<= 1;
        for(int i = 0; i < n; ++i){
            int k = i;
            for(int j = k; j < n; ++j){
                if(a[j] - a[k] > t){
                    break;
                }
                i = j;
            }
            ++cnt;
        }
        return (cnt <= 3);
    };
    ll l = 0, r = 1e9 + 7;
    while(l < r){
        ll mid = (l + r) / 2;
        if(check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << l << '\n';
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
