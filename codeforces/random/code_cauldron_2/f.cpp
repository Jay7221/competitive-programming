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
 
 
int bfs(int mask, int infected, int n, vector<vector<int>> &adj){
    int ans = 0;
    queue<int> q;
    vector<bool> vis(2 * n);
    for(int i = 0; i < 2 * n; ++i){
        if(1 & (mask >> i)){
            vis[i] = true;
        }
    }


    for(int i = 0; i < 2 * n; ++i){
        if(1 & (infected >> i)){
            vis[i] = true;
            q.push(i);
            ++ans;
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adj[u]){
            if(!vis[v]){
                vis[v] = true;
                ++ans;
                q.push(v);
            }
        }
    }
    return (2 * n - ans);
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int infected = 0;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        infected |= (1 << (2 * v + u));
    }

    vector<vector<int>> adj(2 * n, vector<int>());
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 2; ++j){
            int u = 2 * i + j;
            if(i > 0){
                int v = 2 * (i - 1) + j;
                adj[u].push_back(v);
            }
            if(i + 1 < n){
                int v = 2 * (i + 1) + j;
                adj[u].push_back(v);
            }
            adj[u].push_back(2 * i + 1 - j);
        }
    }


    int ans = 0;
    int MAX_MASK = (1 << (2 * n));
    for(int mask = 0; mask < MAX_MASK; ++mask){
        if((mask & infected) > 0){
            continue;
        }
        if(__builtin_popcount(mask) != k){
            continue;
        }
        ans = max(ans, bfs(mask, infected, n, adj));
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
