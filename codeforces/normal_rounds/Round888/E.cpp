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
 
const ll INF = 1e15 + 7;
 
vector<int> topological_sort(vector<vector<int>> &adj){
    int n = adj.size();

    vector<int> order;
    function<void(int)> dfs;
    vector<bool> vis(n);

    dfs = [&](int u){
        vis[u] = true;
        for(int v : adj[u]){
            if(!vis[v]){
                dfs(v);
            }
        }
        order.push_back(u);
    };

    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            dfs(i);
        }
    }

    reverse(order.begin(), order.end());
    return order;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> buy(n), create(n);
    vector<vector<int>> adj(n);
    for(int i = 0; i < n; ++i){
        cin >> buy[i];
    }
    for(int i = 0; i < k; ++i){
        int ind;
        cin >> ind;
        --ind;
        buy[ind] = 0;
    }
    for(int i = 0; i < n; ++i){
        int m;
        cin >> m;
        if(m == 0){
            create[i] = INF;
        }
        for(int j = 0; j < m; ++j){
            int v;
            cin >> v;
            --v;
            adj[v].push_back(i);
        }
    }
    vector<int> order = topological_sort(adj);
    for(int elem : order){
        create[elem] = min(create[elem], buy[elem]);
        for(int v : adj[elem]){
            create[v] += create[elem];
        }
    }
    for(ll c : create){
        cout << c << ' ';
    }
    cout << '\n';
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
 
