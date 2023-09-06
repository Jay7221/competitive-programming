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
    int q;
    cin >> q;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> vis(n);
    int sz = 0;
    set<int> st;
    auto bfs = [&](int u){
        queue<int> q;
        q.push(u);
        while(!q.empty()){
            int u = q.front();
            vis[u] = true;
            ++sz;
            q.pop();
            for(int v : graph[u]){
                if(!vis[v]){
                    q.push(v);
                }
            }
        }
    };
    function<void(int, set<int>&)> dfs;
    dfs = [&](int u, set<int> &univ){
        ++sz;
        vis[u] = true;
        univ.erase(u);
        set<int> st;
        for(int v : graph[u]){
            if(!vis[v]){
                univ.erase(v);
                st.insert(v);
            }
        }
        swap(univ, st);
        for(int v : st){
            // For all nodes that are reachable from u
            dfs(v, univ);
        }
    };
    set<int> univ;
    for(int i = 0; i < n; ++i){
        univ.insert(i);
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            sz = 0;
            if(q == 0){
                bfs(i);
            }
            else{
                dfs(i, univ);
            }
            st.insert(sz);
            ans ^= sz;
        }
    }
    int prev = ans;
    vector<int> a;
    for(int elem : st){
        a.push_back(elem);
    }
    n = a.size();
    for(int i = 0; i < n; ++i){
        ans = max(ans, prev ^ a[i]);
        for(int j = i + 1; j < n; ++j){
            ans = max(ans, prev ^ a[i] ^ a[j]);
            for(int k = j + 1; k < n; ++k){
                ans = max(ans, prev ^ a[i] ^ a[j] ^ a[k]);
            }
        }
    }
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
 
