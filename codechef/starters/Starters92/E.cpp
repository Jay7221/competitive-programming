#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return ((a + b) % MOD);
}
ll mult(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return ((a * b) % MOD);
}
void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = n - 1; i > 0; --i){
        a[i] -= a[i - 1];
    }
    for(int i = 1; i < n; ++i){
        ll tmp = min(a[i], k / i);
        a[0] += tmp;
        a[i] -= tmp;
        k -= tmp * i;
        if((k < i) && (a[i] > 0)){
            --a[i];
            ++a[i - k];
            k = 0;
            break;
        }
    }
    if(k > 0){
        a[0] += k / n;
        k %= n;
        if(k > 0){
            ++a[n - k];
        }
    }
    ll sum = a[0];
    for(int i = 1; i < n; ++i){
        a[i] = add(a[i], a[i - 1]);
        sum = add(sum, a[i]);
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        sum = add(sum, -a[i]);
        ans = add(ans, mult(a[i], sum));
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
