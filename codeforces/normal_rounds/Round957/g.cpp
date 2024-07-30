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
ll fact[MAX], invFact[MAX], inv[MAX];
inline ll add(ll a, ll b){
    return ((a + b) % MOD);
}
inline ll mult(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return ((a * b) % MOD);
}
inline ll mult(vector<ll> v){
    ll res = 1;
    for(ll elem: v){
        res *= elem;
        res %= MOD;
    }
    return res;
}
inline ll com(ll a, ll b){
    if(a < b){
        return 0;
    }
    if(b < 0){
        return 0;
    }
    return mult(fact[a], mult(invFact[a - b], invFact[b]));
}
void pre(){
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
    int n;
    cin >> n;
    int ans = 0;
    for(int k = 1; k <= 2 * n + 1; ++k){
        ll cnt = 0;
        for(int x = 0; 2 * x <= k - 1; ++x){
            int y = k - 1 - 2 * x;
            ll p1 = min(n, k - 1);
            ll p2 = max(n - k, 0);
            if((p1 >= x) && (p2 >= y)){
                cnt += mult({fact[p1], fact[p2], invFact[p1 - x], invFact[p2 -  y], invFact[x], invFact[y]});
                cnt %= MOD;
            }
        }
        ans += (cnt * k) % MOD;
        ans %= MOD;
    }
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
 
