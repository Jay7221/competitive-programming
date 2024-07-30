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
 
const int INF = 1e9 + 7;
int n, k;
vector<vector<int>> adj;
vector<int> leafDist, dp0 , dp1;
 
void dfs(int u, int p = -1){
    bool isLeaf = true;
    for(int v: adj[u]){
        if(v != p){
            isLeaf = false;
            dfs(v, u);
            leafDist[u] = min(leafDist[u], leafDist[v] + 1);
            if(leafDist[v] < k){
                dp0[u] += dp0[v];
                dp1[u] = max(dp1[u], dp1[v]);
            }
            else{
                dp1[u] = max(dp1[u], dp0[v] + dp1[v]);
            }
        }
    }
    if(isLeaf){
        leafDist[u] = 0;
        dp0[u] = 1;
        return;
    }
}
void solve() {
    cin >> n >> k;
    adj = vector<vector<int>>(n, vector<int>());
    leafDist = vector<int>(n, n + 1);
    dp0 = vector<int>(n);
    dp1 = vector<int>(n);

    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);

    cout << (dp0[0] + dp1[0]) << '\n';
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
 
