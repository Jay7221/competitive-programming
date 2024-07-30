struct LazySegmentTree{
    int n;
    vector<ll> L, R, add, val;
    LazySegmentTree(int sz){
        n = 4 * sz;
        L = vector<ll>(n);
        R = vector<ll>(n);
        add = vector<ll>(n);
        val = vector<ll>(n);
        n >>= 1;
        init(1, 0, sz - 1);
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
    void set(int node, int l, int r, ll x){
        if((r < L[node]) || (R[node] < l)) {
            return;
        }
        if((l <= L[node]) && (R[node] <= r)){
            val[node] += x;
            add[node] += x;
        }else{
            set(2 * node, l, r, x);
            set(2 * node + 1, l, r, x);
            val[node] = add[node] + min(val[2 * node], val[2 * node + 1]);
        }
    }
    ll get(int node, int l, int r){
        if((l <= L[node]) && (R[node] <= r)){
            return val[node];
        }
        ll ans = INF;
        if(l <= R[2 * node]){
            ans = min(ans, get(2 * node, l, r));
        }
        if(L[2 * node + 1] <= r){
            ans = min(ans, get(2 * node + 1, l, r));
        }
        ans += add[node];
        return ans;
    }
};

