#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
const int MAX = 1e5 + 7;
vector<ll> fact(MAX);
ll add(ll a, ll b){
    return ((a + b) % MOD);
}
ll sub(ll a, ll b){
    return (((a - b) % MOD + MOD) % MOD);
}
ll mult(ll a, ll b){
    return ((a * b) % MOD);
}
ll power(ll a, ll p){
    ll ans = 1, rem = a;
    while(p > 0){
        if(p & 1){
            ans = mult(ans, rem);
        }
        rem = mult(rem, rem);
        p >>= 1;
    }
    return ans;
}
ll inv(ll a){
    return power(a, MOD - 2);
}
ll divide(ll a, ll b){
    return mult(a, inv(b));
}
void pre(){
    fact[0] = 1;
    for(int i = 1; i < MAX; ++i){
        fact[i] = mult(fact[i - 1], i);
    }
}
ll com(ll a, ll b){
    if(a < b){
        return 0;
    }
    return divide(fact[a], mult(fact[b], fact[a - b]));
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        int p = i;
        int q = n - i - 1;
        ll comp1 = com(p, a[i] - 1);
        ll comp2 = power(2, q);
        ll comp = mult(comp1, comp2);
        ans = add(ans, comp);
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pre();

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
