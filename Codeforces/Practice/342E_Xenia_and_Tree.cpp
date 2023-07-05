#include <bits/stdc++.h>

using namespace std;

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

const ll INF = 1e9 + 7;

struct CentroidDecomposition{
    vector<set<int>> tree;
    vector<int> par;
    vector<int> sub;

    CentroidDecomposition(vector<set<int>> &tree) : tree(tree) {
        int n = tree.size();
        par.resize(n);
        sub.resize(n);
        build(0, -1);
    }

    void build(int u, int p){
        int n = get_subtree_size(u, p);             // find the size of each subtree
        int centroid = get_centroid(u, p, n);          // find the centroid
        par[centroid] = p;

        // for each tree resulting from the removal of the centroid
        set<int> children = tree[centroid];
        for(int v : children){
            tree[v].erase(centroid);        // remove the edge to disconnect the component from the tree
            tree[centroid].erase(v);
            build(v, centroid);
        }
    }

    int get_subtree_size(int u, int p){
        sub[u] = 1;
        for(int v : tree[u]){
            if(v != p){
                sub[u] += get_subtree_size(v, u);
            }
        }
        return sub[u];
    }

    int get_centroid(int u, int p, int n){
        for(int v : tree[u]){
            if((v != p) && ((2 * sub[v]) > n)){
                return get_centroid(v, u, n);
            }
        }
        return u;
    }

    int operator[](int i){
        return par[i];
    }
};
const int LOGMAX = 30;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n);
    vector<vector<int>> par(n, vector<int>(LOGMAX, -1));
    vector<int> depth(n);

    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    function<void(int)> dfs;
    dfs = [&](int u){
        for(int v : adj[u]){
            if(v != par[u][0]){
                depth[v] = depth[u] + 1;
                par[v][0] = u;
                dfs(v);
            }
        }
    };
    dfs(0);
    for(int k = 1; k < LOGMAX; ++k){
        for(int u = 0; u < n; ++u){
            if(par[u][k - 1] != -1){
                par[u][k] = par[par[u][k - 1]][k - 1];
            }
        }
    }
    auto dist = [&](int u, int v){
        if(depth[u] < depth[v]){
            swap(u, v);
        }
        int ans = depth[u] - depth[v];
        for(int k = 0; k < LOGMAX; ++k){
            if((ans >> k) & 1){
                u = par[u][k];
            }
        }
        if(u == v){
            return ans;
        }
        for(int k = LOGMAX - 1; k >= 0; --k){
            if(par[u][k] != par[v][k]){
                u = par[u][k];
                v = par[v][k];
                ans += (1 << (k + 1));
            }
        }
        ans += 2;
        return ans;

    };

    CentroidDecomposition c(adj);
    vector<int> ans(n, INF);

    function<void(int)> update;
    function<int(int)> query;
    update = [&](int u){
        ans[u] = 0;
        for(int p = u; p != -1; p = c[p]){
            ans[p] = min(ans[p], ans[u] + dist(u, p));
        }
    };
    query = [&](int u){
        int res = ans[u];
        for(int p = u; p != -1; p = c[p]){
            res = min(res, ans[p] + dist(u, p));
        }
        return res;
    };

    ans[0] = 0;
    update(0);

    for(int q = 0; q < m; ++q){
        int t, u;
        cin >> t >> u;
        --u;
        if(t == 1){
            update(u);
        }else{
            cout << query(u) << '\n';
        }
    }


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
 
