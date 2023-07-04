#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        a[i] = 1 - a[i];
    }
    vector<ll> b;
    auto debug = [&](vector<ll> &v){
        for(ll elem : v){
            cerr << elem << ' ';
        }
        cerr << '\n';
    };
    for(ll elem : a){
        if(b.size() == 0){
            b.push_back(elem);
        }else{
            if(elem >= 0){
                if(b.back() >= 0){
                    b.back() += elem;
                }else{
                    b.push_back(elem);
                }
            }else{
                if(b.back() < 0){
                    b.back() = min(b.back(), elem);
                }
                else{
                    b.push_back(elem);
                }
            }
        }
    }
    a = b;
    ll ans = 0;
    ll sum = 0;
    ll mn = 0;
    for(ll elem : a){
        sum += elem;
        mn = min(elem, mn);
        sum = max(sum, mn);
        if(sum >= 0){
            ans += sum;
            sum = mn = 0;
        }
    }
    ans += sum;
    cout << ans << '\n';
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
