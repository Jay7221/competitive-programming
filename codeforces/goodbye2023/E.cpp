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
 
class SegmentTree2{
public:
    int n;
    vector<int> arr;
    SegmentTree2(int sz){
        n = 1;
        while(n < sz){
            n <<= 1;
        }
        arr.assign(n, 0);
    }
    int getMax(int l, int r){
        int ans = 0;
        for(int i = l; i <= r; ++i){
            ans = max(ans, arr[i]);
        }
        cerr << "GET2 " << l << ' ' << r << " : " << ans << '\n';
        return ans;
    }
    void addRange(int l, int r, int val){
        cerr << "ADD2 " << l << ' ' << r << " : " << val << '\n';
        for(int i = l; i <= r; ++i){
            arr[i] += val;
        }
    }
};
class SegmentTree{
public:
    int n;
    vector<int> tree;
    vector<int> lazy;
    SegmentTree(int sz){
        n = 1;
        while(n < sz){
            n <<= 1;
        }
        tree.assign(2 * n, 0);
        lazy.assign(2 * n, 0);
    }
    void prop(int node){
        tree[node] += lazy[node];
        if(node < n){
            int l = 2 * node;
            int r = 2 * node + 1;
            lazy[l] += lazy[node];
            lazy[r] += lazy[node];
        }
        lazy[node] = 0;
    }
    void update(int node){
        if(node >= n){
            return;
        }
        int l = 2 * node;
        int r = 2 * node + 1;
        tree[node] = max(tree[l] + lazy[l], tree[r] + lazy[r]);
    }

    int getMax(int l, int r){
        return get(1, l, r, 0, n - 1);
    }
    void addRange(int l, int r, int val){
        add(1, l, r, 0, n - 1, val);
    }

    int get(int node, int tl, int tr, int l, int r){
        if(l > r){
            return 0;
        }
        if((tr < l) || (r < tl)){
            return 0;
        }
        prop(node);
        int ans = 0;
        if((tl <= l) && (r <= tr)){
            ans = tree[node];
        }
        else{
            prop(node);
            int m = (l + r) / 2;
            ans = max({
                get(2 * node    , tl, tr, l     , m),
                get(2 * node + 1, tl, tr, m + 1 , r)
            });
        }
        update(node);
        return ans;
    }
    void add(int node, int tl, int tr, int l, int r, int val){
        if(l > r){
            return;
        }
        if((tr < l) || (r < tl)){
            return;
        }
        prop(node);
        if((tl <= l) && (r <= tr)){
            lazy[node] += val;
        }
        else{
            int m = (l + r) / 2;
            add(2 * node    , tl, tr, l     , m, val);
            add(2 * node + 1, tl, tr, m + 1 , r, val);
        }
        update(node);
    }
};
 
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    // below[i] = vector of nodes in the subtree of i, that are closest to i and have the same color
    vector<vector<int>> below(n);
    vector<int> tin(n), tout(n);
    vector<int> p(n);
    vector<int> a(n);
    for(int i = 1; i < n; ++i){
        cin >> p[i];
        --p[i];
        adj[p[i]].push_back(i);
    }
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        --a[i];
    }
    vector<int> tour;
    vector<vector<int>> colors(n);
    function<void(int)> predfs;
    function<void(int)> dfs;

    predfs = [&](int u){
        int c = a[u];
        if(!colors[c].empty()){
            below[colors[c].back()].push_back(u);
        }
        colors[c].push_back(u);


        tin[u] = tour.size();
        tour.push_back(u);

        for(int v : adj[u]){
            predfs(v);
        }

        tout[u] = tour.size();
        tour.push_back(u);

        colors[c].pop_back();
    };
    predfs(0);

    ll ans = 1;
    int m = tour.size();
    SegmentTree tree(m);
    dfs = [&](int u){
        for(int v : adj[u]){
            dfs(v);
        }
        tree.addRange(tin[u], tout[u], 1);
        for(int v : below[u]){
            tree.addRange(tin[v], tout[v], -1);
        }
        int maxPath = 0;
        for(int v : adj[u]){
            int maxSub = tree.getMax(tin[v], tout[v]);
            ans = max(ans, maxPath * 1ll * maxSub);
            maxPath = max(maxPath, maxSub);
        }
        ans = max(ans, (ll)maxPath);
    };

    dfs(0);
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
 
