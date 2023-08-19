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
 
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
 
#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
 
// -------------------------<RNG>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
 
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    function<void(int, int)> dfs0, dfs1;
    vector<ll> dist(n);
    vector<int> subtree_size(n);
    // dist[i] = sum of distances of all nodes from i
    dfs0 = [&](int u, int p){
        // dfs for finding sum of distances of all nodes in the subtree of u
        subtree_size[u] = 1;
        for(int v : adj[u]){
            if(v == p){
                continue;
            }
            dfs0(v, u);
            subtree_size[u] += subtree_size[v];
            dist[u] += dist[v] + subtree_size[v];
        }
    };
    dfs1 = [&](int u, int p){
        for(int v : adj[u]){
            if(v == p){
                continue;
            }
            dist[v] = dist[u] + n - 2 * subtree_size[v];
            dfs1(v, u);
        }
    };

    dfs0(0, -1);
    dfs1(0, -1);

    for(int i = 0; i < n; ++i){
        cout << dist[i] << ' ';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
