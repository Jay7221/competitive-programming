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
 
 
vector<vector<int>> adj, par;
// val from up to down
vector<int> val1;
// val from down to up
vector<int> val2;
vector<int> depth;
const int MOD = 1e9 + 7;
const int LOGMAX = 30;
void dfs(int u, int p = -1){
    par[u][0] = p;
    for(int v : adj[u]){
        if(v != p){
            depth[v] = depth[u] + 1;
            val1[v] += (26 * val1[u]) % MOD;
            val1[v] %= MOD;
            dfs(v, u);
            val2[u] += (26 * val2[v]) % MOD;
            val2[u] %= MOD;
        }
    }
}
int lca(int u, int v){
    if(depth[u] < depth[v]){
        swap(u, v);
    }
    int diff = depth[u] - depth[v];
    for(int k = 0; k < LOGMAX; ++k){
        if(1 & (diff << k)){
            u = par[u][k];
        }
    }
    if(u == v){
        return u;
    }
    for(int k = LOGMAX - 1; k >= 0; --k){
        if(par[u][k] == -1){
            continue;
        }
        if(par[v][k] == -1){
            continue;
        }
        if(par[u][k] == par[v][k]){
            continue;
        }
        u = par[u][k];
        v = par[v][k];
    }
    return par[u][0];
}
int power(int a, int p){
    int ans = 1;
    while(p > 0){
        if(p & 1){
            ans = (ans * a) % MOD;
        }
        p >>= 1;
        a = (a * a) % MOD;
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    adj = vector<vector<int>>(n);
    par = vector<vector<int>>(n, vector<int>(LOGMAX, -1));
    depth = vector<int>(n);
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    string s;
    cin >> s;
    val1 = vector<int>(n);
    val2 = vector<int>(n);
    for(int i = 0; i < n; ++i){
        val1[i] = val2[i] = s[i] - 'a';
    }
    dfs(0);
    for(int k = 1; k < LOGMAX; ++k){
        for(int u = 0; u < n; ++u){
            if(par[u][k - 1] != -1){
                par[u][k] = par[par[u][k - 1]][k - 1];
            }
        }
    }
    set<int> st;
    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        --u, --v;
        int l = lca(u, v);

        int s1 = val2[u];
        if(par[l][0] != -1){
            int p = par[l][0];
            int len = depth[u] - depth[p];
            s1 -= power(26, len) * val2[p];
            s1 %= MOD;
            s1 += MOD;
            s1 %= MOD;
        }
        int s2 = val2[u];
        if(par[l][0] != -1){
            int p = par[l][0];
            int len = depth[u] - depth[p];
            s2 -= power(26, len) * val2[p];
            s2 %= MOD;
            s2 += MOD;
            s2 %= MOD;
        }

        int len = depth[u] - depth[l];
        int s = s1 + (power(26, len) * s2) % MOD;
        s %= MOD;
        st.insert(s);
    }
    cout << st.size() << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
