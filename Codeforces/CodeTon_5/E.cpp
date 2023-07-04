#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15 + 7;
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
template<typename T>
void debug(vector<T> &arr){
    for(T elem : arr){
        cerr << elem << ' ';
    }
    cerr << '\n';
}
void solve(){
    int n, k, A;
    cin >> n >> k >> A;
    vector<vector<pair<int, int>>> v(k + 1);
    ll sum = 0, ans = 0;
    for(int i = 0; i < n; ++i){
        int x, y, c;
        cin >> x >> y >> c;
        sum += c;
        v[y].push_back({x, c});
    }
    LazySegmentTree s(k + 4);
    for(int x = 0; x <= k; ++x){
        int y = k - x;
        for(auto [x, c] : v[y]){
            s.set(1, 0, x, -c);
        }
        ll fx = x * A + s.get(1, 0, x);
        ans = min(ans, fx);
        s.set(1, x + 1, x + 1, fx - (x + 1) * A);
    }
    cout << (sum + ans) << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
