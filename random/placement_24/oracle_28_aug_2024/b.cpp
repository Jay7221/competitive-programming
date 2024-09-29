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
 
const long long INF = 1e18 + 7;
void dfs(int u, int p, long long activity, vector<vector<pair<int, int>>> &adj, vector<long long> &maxActivity){
    maxActivity[u] = activity;
    for(auto [v, w]: adj[u]){
        if(v != p){
            dfs(v, u, w + max(0ll, activity), adj, maxActivity);
        }
    }
}

 
int getMinServers(int server_nodes, vector<int> server_from, vector<int> server_to, vector<int> server_weight, vector<int> minActivity){
    vector<vector<pair<int, int>>> adj(server_nodes);
    for(int i = 0; i < (int)server_from.size(); ++i){
        --server_from[i];
        --server_to[i];
        adj[server_from[i]].push_back({server_to[i], server_weight[i]});
        adj[server_to[i]].push_back({server_from[i], server_weight[i]});
    }
    vector<long long> maxActivity(server_nodes, -INF);
    dfs(0, -1, -INF, adj, maxActivity);
    int res = 0;
    for(int i = 0; i < server_nodes; ++i){
        if(maxActivity[i] > minActivity[i]){
            ++res;
        }
    }
    return res;
}


void solve() {
    int server_nodes;
    cin >> server_nodes;
    int m;
    cin >> m;
    vector<int> server_from(m);
    vector<int> server_to(m);
    vector<int> server_weight(m);
    vector<int> minActivity(server_nodes);

    for(int i = 0; i < m; ++i){
        cin >> server_from[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> server_to[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> server_weight[i];
    }
    for(int i = 0; i < server_nodes; ++i){
        cin >> minActivity[i];
    }

    cout << getMinServers(server_nodes, server_from, server_to, server_weight, minActivity) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
