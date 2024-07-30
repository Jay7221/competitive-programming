#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
 
const ll MOD = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    ll sum = 0;
    ll ans = 0;
    ll noOpen = 0;
    for(int i  = 0; i < n; ++i){
        ll a;
        cin >> a;
        ans = (ans * 2) % MOD;
        ans = (ans + (sum * a) % MOD) % MOD;
        sum = (sum + a + (a * noOpen) % MOD) % MOD;
        noOpen = (noOpen * 2 + 1) % MOD;
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
