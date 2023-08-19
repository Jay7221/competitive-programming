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
 
 
ll getNumPaths(vector<vector<int>> &adj, int k){
    int n = adj.size();
    vector<vector<int>> paths(n);
    ll ans = 0;
    function<void(int, int)> dfs;
    dfs = [&dfs, &paths, &adj, &n, &k, &ans](int u, int p){
        for(int v : adj[u]){
            if(v == p){
                continue;
            }
            dfs(v, u);
            if(paths[v].size() > paths[u].size()){
                swap(paths[u], paths[v]);
            }
            for(int i = 0; i < paths[v].size(); ++i){
                // the depth of paths at index i is paths[v].size() - i, since we add one for coming above
                int depth = paths[v].size() - i;
                // cnt is number of paths with depth = depth
                ll cnt = paths[v][i];
                if(i > 0){
                    cnt -= paths[v][i - 1];
                }
                // Now we want paths of length >= k with highest node u
                // So assume some part of path has length depth
                // Now we want the other part having length k - depth
                // It will be at depth (k - depth)
                // search for nodes with exactly (k - depth) depth
                int req_depth = k - depth;
                if(req_depth > 0){
                    int req_index = paths[u].size() - req_depth;
                    if((req_index >= 0) && (req_index < paths[u].size())){
                        ll tmp = cnt * paths[u][req_index];
                        ans += tmp;
                    }
                    else{
                        break;
                    }
                }
                else{
                    ans += cnt * paths[u].back();
                }
            }
 
            // merge paths[v] with paths[u]
            for(int i = 0; i < paths[v].size(); ++i){
                int depth = paths[v].size() - i;
                int ind = paths[u].size() - depth;
                paths[u][ind] += paths[v][i];
            }
        }
        // Now consider all paths that end exactly at u
        // Such paths will have depth of atleast k
        int req_index = paths[u].size() - k;
        if((req_index >= 0) && (req_index < paths[u].size())){
            ll tmp = paths[u][req_index];
            ans += tmp;
        }
 
        // Now we will add path consisting of zero depth, or an empty path
        if(paths[u].size() > 0){
            paths[u].push_back(1 + paths[u].back());
        }else{
            paths[u].push_back(1); 
        }
    };
    dfs(0, -1);
    return ans;
}
void solve() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = getNumPaths(adj, k1) - getNumPaths(adj, k2 + 1);
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
