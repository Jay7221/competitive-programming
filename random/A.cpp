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
int get_centroid(int node, vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> subtree_size(n);
    function<int(int, int)> get_subtree_size;
    get_subtree_size = [&](int node, int par){
        int &res = subtree_size[node];
        res = 1;
        for(int i : adj[node]){
            if(i == par){
                continue;
            }
            res += get_subtree_size(i, node);
        }
        return res;
    };
 
    get_subtree_size(node, -1);
 
    bool repeat = true;
    while(repeat){
        repeat = false;
        for(int i : adj[node]){
            if(subtree_size[i] * 2 > n){
                subtree_size[node] -= subtree_size[i];
                subtree_size[i] += subtree_size[node];
 
                node = i;
                repeat = true;
 
                break;
            }
        }
    }
    return node;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> tree(n);
        for(int i = 0; i < n - 1; ++i){
            int u, v;
            cin >> u >> v;
            --u, --v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        int c = get_centroid(0, tree);
        function<void(int, int)> dfs;
        function<void(int, int)> dfs2;
        vector<int> dp(n);
        dfs = [&](int u, int p){
            for(int v : tree[u]){
                if(v != p){
                    dfs(v, u);
                    if(dp[u] < dp[v] + 1){
                        dp[u] = dp[v] + 1;
                    }
                }
            }
        };
        dfs2 = [&](int u, int p){
            for(int v : tree[u]){
                if(v != p){
                    dp[v] = max(dp[v], dp[u] + 1);
                    dfs2(v, u);
                }
            }
        };
        for(int v : tree[c]){
            dfs(v, c);
            dp[c] = max(dp[c], dp[v] + 1);
        }
        multiset<int> st;
        for(int v : tree[c]){
            st.insert(dp[v]);
        }
        for(int v : tree[c]){
            int old_val = dp[v];
            st.erase(st.find(old_val));
            if(!st.empty()){
                int new_val = 2 + *(--st.end());
                if(dp[v] < new_val){
                    dp[v] = new_val;
                    dfs2(v, c);
                }
            }
            st.insert(old_val);
        }
        for(int i = 0; i < n; ++i){
            cout << m * 1ll * dp[i] << '\n';
        }
    }
	return 0;
}

