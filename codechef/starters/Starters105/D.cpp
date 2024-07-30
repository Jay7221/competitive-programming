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
 
 
vector<vector<int>> pre;
vector<vector<int>> suf;
vector<vector<pair<int, char>>> adj;
string s;
int n, m;
int ans;
void dfs(int node, int p){
    for(auto [child, ch] : adj[node]){
        if(child == p){
            continue;
        }
        dfs(child, node);
        for(int i = 1; i <= m; ++i){
            ans = max({ans, pre[node][i - 1] + (ch == s[i]) + suf[child][i + 1], pre[child][i - 1] + (ch == s[i]) + suf[node][i + 1]});
            ans = max({ans, pre[node][i] + suf[child][i + 1], pre[child][i] + suf[node][i + 1]});
        }

        for(int i = 0; i <= m; ++i){
            pre[node][i] = max(pre[node][i], pre[child][i]);
            suf[node][i] = max(suf[node][i], suf[child][i]);
        }

        for(int i = 1; i <= m; ++i){
            pre[node][i] = max(pre[node][i], pre[child][i - 1] + (ch == s[i]));
            suf[node][i] = max(suf[node][i], suf[child][i + 1] + (ch == s[i]));
        }
        for(int i = 1; i <= m; ++i){
            pre[node][i] = max(pre[node][i], pre[node][i - 1]);
        }
        for(int i = m; i > 0; --i){
            suf[node][i] = max(suf[node][i], suf[node][i - 1]);
        }
    }
    cerr << node << ' ' << pre[node] << '\n';
    cerr << node << ' ' << suf[node] << '\n';
    for(int i = 0; i < m; ++i){
        ans = max({ans, pre[node][i], suf[node][i]});
    }
}
void solve() {
    cin >> n;
    adj.assign(n, vector<pair<int, char>>());
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        char ch;
        cin >> u >> v >> ch;
        --u, --v;
        adj[u].push_back({v, ch});
        adj[v].push_back({u, ch});
    }
    cin >> s;
    m = s.size();
    s = "#" + s;
    pre.assign(n, vector<int>(m + 1));
    suf.assign(n, vector<int>(m + 1));
    ans = 0;
    dfs(0, -1);
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
 
