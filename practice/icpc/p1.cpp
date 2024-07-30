#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1e7 + 7;
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll ans = 1;
        while(n){
            ll d = n % 10;
            n /= 10;
            ans *= ((d + 1) * (d + 2)) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}
