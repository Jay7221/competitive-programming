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
const int MAX = 1e6 + 7;
vector<int> d;
void pre(){
    d = vector<int>(MAX, -1);
    d[1] = 1;
    for(int i = 2; i < MAX; ++i){
        if(d[i] == -1){
            for(int j = 1; i * j < MAX; ++j){
                if(d[i * j] == -1){
                    d[i * j] = i;
                }
            }
        }
    }
}

// -------------------------<rng>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
struct SegmentTree{
    vector<ll> tree;
    vector<ll> L, R;
    ll n;
    void init(ll sz){
        n = 1;
        while(n < sz){
            n <<= 1;
        }
        tree = vector<ll>(2 * n);
        L = vector<ll>(2 * n);
        R = vector<ll>(2 * n);
    }
    SegmentTree(){
    }
    SegmentTree(ll sz){
        init(sz);
    }
    SegmentTree(vector<ll> &arr){
        ll sz = arr.size();
        init(sz);
        for(ll i = 0; i < n; ++i){
            L[i + n] = R[i + n] = i;
        }
        for(ll i = 0; i < sz; ++i){
            tree[i + n] = arr[i];
        }
        for(ll i = n - 1; i > 0; --i){
            tree[i] = tree[2 * i] + tree[2 * i + 1];
            L[i] = L[2 * i];
            R[i] = R[2 * i + 1];
        }
    }
    void set(ll ind, ll val){
        ind += n;
        tree[ind] = val;
        ind >>= 1;
        while(ind > 0){
            tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
            ind >>= 1;
        }
    }
    ll get(ll l, ll r){
        l += n;
        r += n;
        ll res = 0;
        while(l <= r){
            if((l & 1) == 1){
                res += tree[l];
                ++l;
            }
            if((r & 1) == 0){
                res += tree[r];
                --r;
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
    void update(ll l, ll r, ll node = 1){
        if((R[node] < l) || (r < L[node])){
            return;
        }
        if(tree[node] < min(r - l, R[node] - L[node])){
            return;
        }
        ll left = 2 * node;
        ll right = 2 * node + 1;
        if(L[node] == R[node]){
            tree[node] /=  d[tree[node]];
        }
        else{
            update(l, r, left);
            update(l, r,  right);
            tree[node] = tree[left] + tree[right];
        }
    }
};
 
void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(ll i = 0; i < n; ++i){
        cin >> arr[i];
    }
    SegmentTree segtree(arr);
    while(q--){
        ll type;
        cin >> type;
        if(type == 1){
            ll l, r;
            cin >> l >> r;
            --l, --r;
            segtree.update(l, r);
        }
        else if(type == 2){
            ll l, r;
            cin >> l >> r;
            --l, --r;
            cout << segtree.get(l, r) << '\n';
        }
        else{
            ll i, k;
            cin >> i >> k;
            --i;
            segtree.set(i, k);
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
 
