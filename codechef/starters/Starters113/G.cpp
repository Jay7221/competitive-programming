#include <bits/stdc++.h>
 
using namespace std;
 
//#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
#define ll long long
#define ld long double
 
#define PI 3.1415926535897932384626433832795l 

// -------------------------<rng>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
const ll MOD = 998244353;
const int MAX = 2e6 + 7;
vector<ll> fact, inv, invFact;
ll add(ll a, ll b){
    return (((a + b) % MOD + MOD) % MOD);
}
ll sub(ll a, ll b){
    return (((a - b) % MOD + MOD) % MOD);
}
ll mult(ll a, ll b){
    return (((a * b) % MOD + MOD) % MOD);
}
ll power(ll a, ll p){
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
    return mult(a, inv[b]);
}
ll com(ll a, ll b){
    if(a < b){
        return 0ll;
    }
    if(b < 0){
        return 0ll;
    }
    return mult(fact[a], mult(invFact[a - b], invFact[b]));
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
 
void solve() {
    int n, k, v;
    cin >> n >> k >> v;
    ll ans = 0;

    for(int i = 1; i < v; ++i){
        ll cur = com(n - 1 - i, k - 1);
        cur = mult(cur, fact[n - 1]);
        cur = mult(cur, mult(fact[k - 1], invFact[k]));
        cerr << i << ' ' << cur << '\n';
        ans = add(ans, cur);
    }
    ll cur = com(n - v, k - 1);
    cur = mult(cur, fact[n - 1]);
    ans = add(ans, cur);
    for(int i = v + 1; i <= n; ++i){
        ll cur = com(n - i, k - 1);
        cur = mult(cur, fact[n - 1]);
        cur = mult(cur, mult(fact[k - 1], invFact[k]));
        cerr << i << ' ' << cur << '\n';
        ans = add(ans, cur);
    }
    cerr << "----------------\n";

    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    pre();
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
