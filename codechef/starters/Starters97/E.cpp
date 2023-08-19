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
 
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
 
#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
 
#define SIZE 4
#define bs bitset<SIZE>
// -------------------------<RNG>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers
struct LazySegmentTree{
    int n;
    int N;
    vector<ll> L, R;
    vector<bs> val, lazy_add, lazy_rem;
    LazySegmentTree(int sz){
        n = 4 * sz;
        N = n;
        L = vector<ll>(n);
        R = vector<ll>(n);
        val = vector<bs>(n);
        lazy_add = vector<bs>(n);
        lazy_rem = vector<bs>(n);
        for(int i = 0; i < SIZE; ++i){
            lazy_add[0][i] = 0;
            lazy_rem[0][i] = 1;
        }
        for(int i = 1; i < n; ++i){
            lazy_add[i] = lazy_add[0];
            lazy_rem[i] = lazy_rem[0];
        }
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
    void update(int node){
        int left = 2 * node;
        int right = 2 * node + 1;
        val[node] = val[left] & val[right];
    }
    bs f(bs a, bs lz_add, bs lz_rem){
        return ((a & lz_rem) | lz_add);
    }
    void prop(int node){
        int left = 2 * node;
        int right = 2 * node + 1;

        val[left] = f(val[left], lazy_add[node], lazy_rem[node]);
        val[right] = f(val[right], lazy_add[node], lazy_rem[node]);

        lazy_add[left] = f(lazy_add[left], lazy_add[node], lazy_rem[node]);
        lazy_add[right] = f(lazy_add[right], lazy_add[node], lazy_rem[node]);

        lazy_rem[left] = f(lazy_rem[left], lazy_add[node], lazy_rem[node]);
        lazy_rem[right] = f(lazy_rem[right], lazy_add[node], lazy_rem[node]);

        lazy_add[node] = lazy_add[0];
        lazy_rem[node] = lazy_rem[0];
    }
    void add(int node, int l, int r, int ind){
        if(node >= N){
            return;
        }
        if((r < L[node]) || (R[node] < l)) {
            return;
        }
        if((l <= L[node]) && (R[node] <= r)){
            val[node][ind] = 1;
            lazy_add[node][ind] = 1;
            lazy_rem[node][ind] = 1;
        }else{
            prop(node);
            add(2 * node, l, r, ind);
            add(2 * node + 1, l, r, ind);
            update(node);
        }
    }
    void remove(int node, int l, int r, int ind){
        if(node >= N){
            return;
        }
        if((r < L[node]) || (R[node] < l)) {
            return;
        }
        if((l <= L[node]) && (R[node] <= r)){
            val[node][ind] = 0;
            lazy_add[node][ind] = 0;
            lazy_rem[node][ind] = 0;
        }else{
            prop(node);
            remove(2 * node, l, r, ind);
            remove(2 * node + 1, l, r, ind);
            update(node);
        }
    }
    bs get(int node, int l, int r){
        if((r < L[node]) || (R[node] < l)){
            return lazy_rem[0];
        }
        if((l <= L[node]) && (R[node] <= r)){
            return val[node];
        }
        prop(node);
        return (get(2 * node, l, r) & get(2 * node + 1, l, r));
    }
};

 
const int MAX = 701;
vector<int> primes;
void pre(){
    vector<bool> isPrime(MAX, true);
    for(int i = 2; i < MAX; ++i){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j = 2; i * j < MAX; ++j){
                isPrime[i * j] = false;
            }
        }
    }
}
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> in(n), out(n);
    function<void(int, int)> dfs;
    int timer = 0;
    dfs = [&](int u, int p){
        in[u] = timer;
        ++timer;
        for(int v : adj[u]){
            if(v == p){
                continue;
            }
            dfs(v, u);
        }
        out[u] = timer;
        ++timer;
    };
    dfs(0, -1);
    map<int, int> indexOf;
    for(int i = 0; i < primes.size(); ++i){
        indexOf[primes[i]] = i;
    }
    LazySegmentTree s(2 * n);
    for(int i = 0; i < n; ++i){
        for(int p : primes){
            if(v[i] % p == 0){
                s.add(1, in[i], in[i], indexOf[p]);
            }
        }
    }
    for(int i = 0; i < n; ++i){
        cerr << i << " : " << in[i] << ' ' << out[i] << " : " << s.get(1, in[i], out[i]) << '\n';
    }
    while(q--){
        int t, u;
        cin >> t >> u;
        --u;
        cerr << "-----------------------------------\n";
        cerr << t << ' ' << u << '\n';
        if(t == 1){
            int p;
            cin >> p;
            s.add(1, in[u], out[u], indexOf[p]);
        }else if(t == 2){
            int p;
            cin >> p;
            s.remove(1, in[u], out[u], indexOf[p]);
        }else{
            bitset<SIZE> b = s.get(1, in[u], out[u]);
            int ans = 0;
            for(int i = 0; i < SIZE; ++i){
                ans += b[i];
            }
            cout << ans << '\n';
        }
        for(int i = 0; i < n; ++i){
            cerr << i << " : " << in[i] << ' ' << out[i] << " : " << s.get(1, in[i], out[i]) << '\n';
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    pre();
    solve();
    
    return 0;
}
 
