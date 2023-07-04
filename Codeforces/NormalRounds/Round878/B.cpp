#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n , k;
    cin >> n >> k;
    ll tmp = 1;
    while(k--){
        tmp <<= 1;
        if(tmp > n){
            break;
        }
    }
    tmp -= 1;
    if(tmp < n){
        n = tmp;
    }
    ll ans = n + 1ll;
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
