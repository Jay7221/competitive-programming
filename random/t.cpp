#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 1e9 + 7;
static const int MAX = 2e5 + 7;
vector<ll> fact, inv, invFact;
ll add(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return ((a + b) % MOD);
}
ll sub(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return (((a - b) % MOD + MOD) % MOD);
}
ll mult(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return ((a * b) % MOD);
}
ll power(ll a, ll p){
    a = ((a % MOD) + MOD) % MOD;
    ll ans = 1;
    while(p > 0){
        if(p & 1){
            ans = mult(ans, a);
        }
        a = mult(a, a);
        p >>= 1;
    }
    return ans;
}
ll divide(ll a, ll b){
    if(b < MAX){
        return mult(a, inv[b]);
    }
    return mult(a, power(b, MOD - 2));
}
ll com(ll a, ll b){
    if(a < b){
        return 0;
    }
    if(b < 0){
        return 0;
    }
    return divide(fact[a], mult(fact[a - b], fact[b]));
}
void pre(){
    fact = vector<ll>(MAX);
    inv= vector<ll>(MAX);
    invFact = vector<ll>(MAX);
    fact[0] = fact[1] = inv[1] = invFact[0] = invFact[1] = 1;
    for(int i = 2; i < MAX; ++i){
        ll q = MOD / i;
        ll r = MOD % i;
        inv[i] = mult(-q, inv[r]);
        fact[i] = mult(i, fact[i - 1]);
        invFact[i] = mult(inv[i], invFact[i - 1]);
    }
}
int main(){
    pre();
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 1;
    ll s = a[0];
    for(int i = 1; i < n; ++i){
        ans = mult(ans, com(s + 1, a[i]));
        s += a[i];
    }
    cout << ans << '\n';
}
