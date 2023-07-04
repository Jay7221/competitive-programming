#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 7;
struct LazySegmentTree{
    const ll INF = 1e15 + 7;
    int n;
    vector<ll> L, R, add, val;
    LazySegmentTree(int sz){
        n = 4 * sz;
        L = vector<ll>(n);
        R = vector<ll>(n);
        add = vector<ll>(n);
        val = vector<ll>(n);
        n >>= 1;
        init(1, 0, sz);
    }
    void init(int node, int l, int r){
        if(l > r){
            return;
        }
        L[node] = l;
        R[node] = r;
        if(l < r){
            int mid = (l + r) / 2;
            init(2 * node, l, mid);
            init(2 * node + 1, mid + 1, r);
        }
    }
    void prop(int u){
        int l = 2 * u, r = 2 * u + 1;
        add[l] += add[u];
        add[r] += add[u];
        add[u] = 0;
    }
    void update(int u){
        int l = 2 * u, r = 2 * u + 1;
        val[u] = val[l] + val[r] + (add[l] * (R[l] - L[l]) + add[r] * (R[r] - L[r]));
    }
    void set(int node, int l, int r, ll x){
        if((r < L[node]) || (R[node] < l)) {
            return;
        }
        if((l <= L[node]) && (R[node] <= r)){
            val[node] += x;
            add[node] += x;
        }else{
            prop(node);
            set(2 * node, l, r, x);
            set(2 * node + 1, l, r, x);
            update(node);
        }
    }
    ll get(int node, int l, int r){
        if((l <= L[node]) && (R[node] <= r)){
            return val[node] + (add[node] * (R[node] - L[node]));
        }
        ll ans = 0;

        prop(node);

        if(l <= R[2 * node]){
            ans += get(2 * node, l, r);
        }
        if(L[2 * node + 1] <= r){
            ans += get(2 * node + 1, l, r);
        }
        return ans;
    }
};

struct Trie{
    const int LOGMAX = 20;
    vector<vector<int>> trie;
    vector<vector<int>> par;
    int n;
    Trie(){
        n = 1;
        trie.push_back(vector<int>(26, -1));
        par.push_back(vector<int>(LOGMAX, -1));
    }
    void addNode(int p, int k){
        trie[p][k] = n;

        trie.push_back(vector<int>(26, -1));
        par.push_back(vector<int>(LOGMAX, -1));
        par[n][0] = p;

        for(int k = 1; k < LOGMAX; ++k){
            if(par[n][k - 1] != -1){
                par[n][k] = par[par[n][k - 1]][k - 1];
            }
        }

        ++n;
    }
    int insert(int u, string s){
        for(char ch : s){
            int k = ch - 'a';
            if(trie[u][k] == -1){
                addNode(u, k);
            }
            u = trie[u][k];
        }
        return u;
    }
    int kth(int u, int k){
        for(int j = 0; j < LOGMAX; ++j){
            if((k >> j) & 1){
                u = par[u][j];
            }
        }
        return u;
    }
};

void solve(){
    int n;
    cin >> n;
    string s;
    Trie tr;
    vector<int> leaf(N), oldVal(N), sz(N);
    LazySegmentTree st(N);

    for(int i = 0; i < n; ++i){
        cin >> s;
        sz[i] = s.size();
        leaf[i] = tr.insert(0, s);
    }

    int q;
    cin >> q;

    vector<tuple<int, int, int, int, string>> v;
    int t, i, k, x, cnt = 0;
    for(int j = 0; j < q; ++j){
        cin >> t >> i;
        if(t == 1){
            cin >> k >> x;
            --k;
        }else if(t == 2){
            cin >> k >> s;
            --k;

            sz[n + cnt] = k + 1 + s.size();
            leaf[n + cnt] = tr.insert(tr.kth(leaf[i], sz[i] - k - 1), s);

            ++cnt;
        }
        v.push_back({t, i, k, x, s});
    }
    /*

    dfs(0);

    cnt = 0;
    return;
    for(auto [t, i, k, x, s] : v){
        if(t == 1){
            u = kth(leaf[i], sz[i] - k - 1);
            st.set(1, in[u], out[u], x);
        }
        else if(t == 2){
            oldVal[n + cnt] = st.query(1, in[leaf[n + cnt]], in[leaf[n + cnt]]);
            cnt++;
        }
        else{
            cout << st.query(1, in[leaf[i]], in[leaf[i]]) - oldVal[i] << '\n';
        }
    }

    */
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
