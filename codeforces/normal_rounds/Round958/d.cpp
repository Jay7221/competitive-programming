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
 
const ll INF = 1e18 + 7;
const ll NUM_ROUNDS = 25;

vector<vector<ll>> adj;
vector<ll> a;
vector<vector<ll>> dp;

void dfs(ll u, ll p){
    // dp[i][j] = monster i killed in round j
    for(ll j = 0; j < NUM_ROUNDS; ++j){
        dp[u][j] = (j + 1) * a[u];
    }
    for(ll child: adj[u]){
        if(child != p){
            dfs(child, u);
            for(ll j = 0; j < NUM_ROUNDS; ++j){
                ll tmp = INF;
                for(ll k = 0; k < NUM_ROUNDS; ++k){
                    if(k != j){
                        tmp = min(tmp, dp[child][k]);
                    }
                }
                dp[u][j] += tmp;
            }
        }
    }
    for(ll j = 0; j < NUM_ROUNDS; ++j){
        assert(dp[u][j] >= 0);
    }
}
 
void solve() {
    ll n;
    cin >> n;

    a = vector<ll>(n);
    dp = vector<vector<ll>>(n, vector<ll>(NUM_ROUNDS));
    adj = vector<vector<ll>>(n);

    for(ll i = 0; i < n; ++i){
        cin >> a[i];
    }

    for(ll i = 0; i < n - 1; ++i){
        ll x, y;
        cin >> x >> y;
        --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0, -1);

    cout << *min_element(dp[0].begin(), dp[0].end()) << '\n';;
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
 
