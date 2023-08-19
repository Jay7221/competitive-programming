#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct SegmentTree{
    ll f(ll a, ll b){
        return (a + b);
    }
    vector<ll> tree;
    int n;
    void init(int sz){
        n = 1;
        while(n < sz){
            n <<= 1;
        }
        tree = vector<ll>(2 * n);
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
    void set(int ind, int val){
        ind += n;
        tree[ind] = val;
        ind >>= 1;
        while(ind > 0){
            tree[ind] = f(tree[2 * ind], tree[2 * ind + 1]);
            ind >>= 1;
        }
    }
    ll get(int l, int r){
        l += n;
        r += n;
        ll res = 0;
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
vector<vector<int>> graph;
vector<int> val;
vector<int> path;
vector<int> in, out;
void dfs(int u, int p){
    in[u] = path.size();
    path.push_back(u);
    
    for(int v : graph[u]){
        if(v != p){
            dfs(v, u);
        }
    }

    out[u] = path.size();
    path.push_back(u);
}
void solve(){
    int n, q;
    cin >> n >> q;

    val = vector<int>(n);
    in = vector<int>(n);
    out = vector<int>(n);
    graph = vector<vector<int>>(n);


    for(int i = 0; i < n; ++i){
        cin >> val[i];
    }
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0, -1);
    SegmentTree s(2 * n);
    for(int i = 0; i < n; ++i){
        s.set(in[i], val[i]);
        s.set(out[i], val[i]);
    }

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int i, x;
            cin >> i >> x;
            --i;

            val[i] = x;
            s.set(in[i], val[i]);
            s.set(out[i], val[i]);

        }else{
            int i;
            cin >> i;
            --i;
            cout << (s.get(in[i], out[i]) / 2) << '\n';
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
