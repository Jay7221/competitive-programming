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
 
const ll MOD = 1e9 + 7;
struct LazySegmentTree{
    ll n;
    vector<ll> L, R;
    vector<ll> minval, maxval, minind, maxind;
    vector<bool> prop;
    LazySegmentTree(vector<ll> &arr){
        ll sz = arr.size();
        n = 8 * sz;
        minval = vector<ll>(n);
        maxval = vector<ll>(n);
        minind = vector<ll>(n);
        maxind = vector<ll>(n);
        prop = vector<bool>(n);
        L = vector<ll>(n);
        R = vector<ll>(n);
        init(1, 0, sz - 1, arr);
    }
    void init(ll node, ll l, ll r, vector<ll> &arr){
        if(l > r){
            return;
        }
        L[node] = l;
        R[node] = r;
        if(l < r){
            ll mid = (l + r) / 2;
            ll left = 2 * node;
            ll right = 2 * node + 1;
            init(left, l, mid, arr);
            init(right, mid + 1, r, arr);
            update(node);
        }
        else{
            assert(l < (int)arr.size());
            minval[node] = maxval[node] = arr[l];
            minind[node] = maxind[node] = l;
        }
    }
    void update(ll node){
        ll left = 2 * node;
        ll right = 2 * node + 1;
        if(minval[left] <= minval[right]){
            minval[node] = minval[left];
            minind[node] = minind[left];
        }
        else{
            minval[node] = minval[right];
            minind[node] = minind[right];
        }
        if(maxval[left] >= maxval[right]){
            maxval[node] = maxval[left];
            maxind[node] = maxind[left];
        }
        else{
            maxval[node] = maxval[right];
            maxind[node] = maxind[right];
        }
    }
    void propogate(ll node){
        ll left = 2 * node;
        ll right = 2 * node + 1;
        if(prop[node]){
            multiply(left);
            multiply(right);
            prop[node] = false;
        }
    }
    void multiply(ll node){
        ll tmp = minval[node];
        minval[node] = MOD - maxval[node];
        maxval[node] = MOD - tmp;
        swap(minind[node], maxind[node]);
        prop[node] = (prop[node] ^ 1);
    }
    void multiply(ll node, ll l, ll r){
        if((l <= L[node]) && (R[node] <= r)){
            // node lies completely within [l, r]
            multiply(node);
            return;
        }
        if((R[node] < l) || (r < L[node])){
            // node lies outside [l, r]
            return;
        }
        ll left = 2 * node;
        ll right = 2 * node + 1;
        propogate(node);
        multiply(left, l, r);
        multiply(right, l, r);
        update(node);
    }
};

 
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
    }
    LazySegmentTree tree(a);
    ll q;
    cin >> q;
    ll ans = 0;
    while(q--){
        ll l, r;
        cin >> l >> r;
        --l, --r;
        tree.multiply(1, l, r);
        int max_ind = tree.maxind[1] + 1;
        ans += max_ind;
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    ll tc;
    cin >> tc;
    for(ll t = 1; t <= tc; ++t){
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}
 
