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
 
 
void solve() {
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;
    --a, --b;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> path;

    function<int(int, int)> dfs1 = [&](int u, int p){
        if(u == a){
            path.push_back(u);
            return true;
        }
        for(int v: adj[u]){
            if((v != p) && dfs1(v, u)){
                path.push_back(u);
                return true;
            }
        }
        return false;
    };


    // dp1 = cost with return
    // dp2 = cost without return
    vector<int> dp1(n), dp2(n);

    function<void(int, int)> dfs2 = [&](int u, int p){
        for(int v: adj[u]){
            if(v != p){
                dfs2(v, u);
                dp1[u] += 2 + dp1[v];
            }
        }
        dp2[u] = dp1[u];
        for(int v: adj[u]){
            if(v != p){
                dp2[u] = min(dp2[u], dp1[u] - dp1[v] + dp2[v] - 1);
		// dp1[u] - (2 + dp1[v]) + (1 + dp2[v])
            }
        }
    };

    dfs1(b, -1);

    int m = path.size();
    int c = path[(m - 1) / 2];
    dfs2(c, -1);

    int ans = (m / 2) + dp2[c];
    cout << ans << '\n';
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
 
