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
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<bool> isBlack(n);
    for(int i = 0; i < k; ++i){
        int u;
        cin >> u;
        --u;
        isBlack[u] = true;
    }
    vector<int> deg(n);
    vector<pair<int, int>> edges;
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        ++deg[u];
        ++deg[v];
        edges.push_back({u, v});
    }


    ll sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; ++i){
        if(isBlack[i]){
            sum1 = add(sum1, deg[i]);
        }
    }
    for(auto [u, v]: edges){
        if(isBlack[u] && isBlack[v]){
            sum2 = add(sum2, 1);
        }
    }


    for(int i = 1; i <= k; ++i){
        ll ans = mult(sum1, com(k - 1, i - 1));
        ans = sub(ans, mult(sum2, com(k - 2, i - 2)));
        ans = divide(ans, com(k, i));
        ans = sub(ans, i - 1);
        cout << ans << ' ';
    }
    cout << '\n';

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
 
