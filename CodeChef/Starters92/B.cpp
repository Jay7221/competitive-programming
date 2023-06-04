#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
void solve(){
    int n, k;
    cin >> n >> k;
    ll ans = 1;
    for(int i = k; i >= max(1, k - n + 1); --i){
        ans = (ans * i) % MOD;
    }
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
