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
 
const int LOGMAX = 31;

struct SegmentTree{
    int f(int a, int b){
        return (a + b);
    }
    vector<int> tree;
    int n;
    void init(int sz){
        n = 1;
        while(n < sz){
            n <<= 1;
        }
        tree = vector<int>(2 * n);
    }
    SegmentTree(){
    }
    SegmentTree(int sz){
        init(sz);
    }
    SegmentTree(vector<int> &arr){
        int sz = arr.size();
        init(sz);
        for(int i = 0; i < sz; ++i){
            tree[i + n] = arr[i];
        }
        for(int i = n - 1; i > 0; --i){
            tree[i] = f(tree[2 * i], tree[2 * i + 1]);
        }
    }
    void update(int ind, int val){
        ind += n;
        tree[ind] = val;
        ind >>= 1;
        while(ind > 0){
            tree[ind] = f(tree[2 * ind], tree[2 * ind + 1]);
            ind >>= 1;
        }
    }
    int query(int l, int r){
        l += n;
        r += n;
        int res = 0;
        while(l <= r){
            if((l & 1) == 1){
                res = f(res, tree[l]);
                ++l;
            }
            if((r & 1) == 0){
                res =  f(res, tree[r]);
                --r;
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};


class HLD {
public:
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos;
    SegmentTree* segTree;
    int cur_pos;

    HLD(vector<vector<int>>& adj, vector<int>& values) {
        int n = adj.size();
        this->adj = adj;
        parent.resize(n);
        depth.resize(n);
        heavy.resize(n, -1);
        head.resize(n);
        pos.resize(n);
        cur_pos = 0;

        dfs(0);
        decompose(0, 0);

        vector<int> base_array(n);
        for (int i = 0; i < n; ++i) {
            base_array[pos[i]] = values[i];
        }

        segTree = new SegmentTree(base_array);
    }

    int dfs(int v) {
        int size = 1;
        int max_c_size = 0;
        for (int c : adj[v]) {
            if (c == parent[v]) continue;
            parent[c] = v;
            depth[c] = depth[v] + 1;
            int c_size = dfs(c);
            size += c_size;
            if (c_size > max_c_size) {
                max_c_size = c_size;
                heavy[v] = c;
            }
        }
        return size;
    }

    void decompose(int v, int h) {
        head[v] = h;
        pos[v] = cur_pos++;
        if (heavy[v] != -1)
            decompose(heavy[v], h);
        for (int c : adj[v]) {
            if (c != parent[v] && c != heavy[v])
                decompose(c, c);
        }
    }

    void update(int v, int value) {
        segTree->update(pos[v], value);
    }

    int query(int a, int b) {
        int res = 0;
        for (; head[a] != head[b]; b = parent[head[b]]) {
            if (depth[head[a]] > depth[head[b]])
                swap(a, b);
            res += segTree->query(pos[head[b]], pos[b]);
        }
        if (depth[a] > depth[b])
            swap(a, b);
        res += segTree->query(pos[a], pos[b]);
        return res;
    }
};
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> c(n);
    vector<vector<int>> adj(n);
    vector<vector<int>> par(n, vector<int>(LOGMAX));
    vector<int> depth(n);

    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    function<void(int, int)> dfs = [&](int u, int p){
        par[u][0] = p;
        for(int v: adj[u]){
            if(v != p){
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        }
    };
    dfs(0, 0);
    for(int k = 1; k < LOGMAX; ++k){
        for(int u = 0; u < n; ++u){
            par[u][k] = par[par[u][k - 1]][k - 1];
        }
    }
    auto lca = [&](int u, int v){
        if(depth[u] < depth[v]){
            swap(u, v);
        }
        int diff = depth[u] - depth[v];
        for(int k = 0; k < LOGMAX; ++k){
            if(1 & (diff >> k)){
                u = par[u][k];
            }
        }
        if(u == v){
            return u;
        }
        for(int k = LOGMAX - 1; k >= 0; --k){
            if(par[u][k] != par[v][k]){
                u = par[u][k];
                v = par[v][k];
            }
        }
        return par[u][0];
    };

    vector<set<int>> freq(n);
    set<int> stf1, stf2;

    auto add_freq = [&](int u){
        freq[depth[u]].insert(u);
        if(freq[depth[u]].size() == 1){
            stf1.insert(depth[u]);
        }
        else if(freq[depth[u]].size() == 2){
            stf1.erase(depth[u]);
            stf2.insert(depth[u]);
        }
        else{
            stf2.erase(depth[u]);
        }
    };
    auto remove_freq = [&](int u){
        freq[depth[u]].erase(u);
        if(freq[depth[u]].size() == 0){
            stf1.erase(depth[u]);
        }
        if(freq[depth[u]].size() == 1){
            stf1.insert(depth[u]);
            stf2.erase(depth[u]);
        }
        else if(freq[depth[u]].size() == 2){
            stf2.insert(depth[u]);
        }
    };

    set<pair<int, int>> st;
    for(int i = 0; i < n; ++i){
        if(c[i] == 1){
            st.insert({depth[i], i});
            add_freq(i);
        }
    }

    HLD hld(adj, c);


    auto update = [&](int u){
        c[u] = 1 - c[u];
        if(c[u] == 0){
            st.erase({depth[u], u});
            remove_freq(u);
        }
        else{
            st.insert({depth[u], u});
            add_freq(u);
        }
        hld.update(u, c[u]);
    };

    auto check = [&](){
        if(st.empty()){
            return false;
        }
        int u = 0, v = 0, _;
        if(stf1.empty()){
            int d = *(--stf2.end());
            u = *freq[d].begin();
            v = *(--freq[d].end());
        }
        else if(stf2.empty()){
            int d1 = *(--stf1.end());
            int d2 = *stf1.begin();
            u = *freq[d1].begin();
            v = *freq[d2].begin();
        }
        else{
            int d1 = *(--stf1.end());
            int d2 = *(--stf2.end());
            if(d1 > d2){
                u = *freq[d1].begin();
                v = *freq[d2].begin();
                if(lca(u, v) == v){
                    v = *(--freq[d2].end());
                }
            }
            else{
                if(stf1.size() > 1){
                    return false;
                }
                int d = *(--stf2.end());
                u = *freq[d].begin();
                v = *(--freq[d].end());
            }
        }

        int l = lca(u, v);
        int p1 = (depth[u] - depth[l] + 1);
        int p2 = (depth[v] - depth[l] + 1);
        if(p1 + p2 - 1 != (int)st.size()){
            return false;
        }
        return (hld.query(u, v) == (int)st.size());
    };

    while(q--){
        int u;
        cin >> u;
        --u;

        update(u);

        if(check()){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
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
 
