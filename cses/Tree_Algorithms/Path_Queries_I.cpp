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
struct HLD{
    vector<int> parent, depth, head, heavy, pos;
    vector<int> arr;
    SegmentTree s;
    int cur_pos;
    int dfs(int v, vector<vector<int>> &graph){
        int size = 1;
        int max_c_size = 0;
        for(int c : graph[v]){
            if(c != parent[v]){
                parent[c] = v;
                depth[c] = depth[v] + 1;
                int c_size = dfs(c, graph);
                size += c_size;
                if(c_size > max_c_size){
                    max_c_size = c_size;
                    heavy[v] = c;
                }
            }
        }
        return size;
    }
    void decompose(int v, int h, vector<vector<int>> &graph){
        head[v] = h;
        pos[v] = cur_pos;
        ++cur_pos;

        if(heavy[v] != -1){
            decompose(heavy[v], h, graph);
        }
        for(int c : graph[v]){
            if((c != parent[v]) && (c != heavy[v])){
                decompose(c, c, graph);
            }
        }

    }
    HLD(vector<vector<int>> &graph){
        int n = graph.size();
        parent = vector<int>(n);
        depth = vector<int>(n);
        heavy = vector<int>(n, -1);
        head = vector<int>(n);
        pos = vector<int>(n);
        arr = vector<int>(n);

        cur_pos = 0;

        dfs(0, graph);
        decompose(0, 0, graph);
        s = SegmentTree(n);
    }

    void set(int v, int val){
        arr[pos[v]] = val;
        s.set(pos[v], val);
    }

    ll get(int l, int r){
        return s.get(l, r);
    }

    ll query(int a, int b){
        ll res = 0;
        while(head[a] != head[b]){
            if(depth[head[a]] > depth[head[b]]){
                swap(a, b);
            }
            ll cur_heavy_path_sum = get(pos[head[b]], pos[b]);
            res += cur_heavy_path_sum;

            b = parent[head[b]];
        }
        if(depth[a] > depth[b]){
            swap(a, b);
        }
        ll last_heavy_path_sum = get(pos[a], pos[b]);
        res += last_heavy_path_sum;

        return res;
    }

};
void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> val(n);
    for(int i = 0; i < n; ++i){
        cin >> val[i];
    }
    vector<vector<int>> tree(n);
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    HLD h(tree);
    for(int i = 0; i < n; ++i){
        h.set(i, val[i]);
    }
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int s, x;
            cin >> s >> x;
            --s;
            h.set(s, x);
        }else{
            int  b;
            cin >> b;
            --b;
            cout << h.query(0, b) << '\n';
        }
    }
    for(int i = 0; i < n; ++i){
        cerr << h.query(i, i) << ' ';
    }
    cerr << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
