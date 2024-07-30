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
 
struct SegmentTree{
    ll f(ll a, ll b){
        return (a + b);
    }
    vector<ll> tree;
    ll n;
    void init(ll sz){
        n = 1;
        while(n < sz){
            n <<= 1;
        }
        tree = vector<ll>(2 * n);
    }
    SegmentTree(){
    }
    SegmentTree(ll sz){
        init(sz);
    }
    SegmentTree(vector<ll> &arr){
        ll sz = arr.size();
        init(sz);
        for(ll i = 0; i < sz; ++i){
            tree[i + n] = arr[i];
        }
        for(ll i = n - 1; i > 0; --i){
            tree[i] = f(tree[2 * i], tree[2 * i + 1]);
        }
    }
    void set(ll ind, ll val){
        ind += n;
        tree[ind] = val;
        ind >>= 1;
        while(ind > 0){
            tree[ind] = f(tree[2 * ind], tree[2 * ind + 1]);
            ind >>= 1;
        }
    }
    ll get(ll l, ll r){
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

vector<ll> numberOfIntersectingRanges(ll n, 
        vector<pair<ll, ll>> &queries, 
        vector<pair<ll, ll>> &ranges){
    ll m = queries.size();
    vector<ll> res(m);
    SegmentTree tree(n);
    vector<tuple<ll, ll, ll>> v;

    for(ll i = 0; i < m; ++i){
        ll l, r;
        tie(l, r) = queries[i];
        v.push_back({l, i, r});
    }
    for(auto [l, r]: ranges){
        v.push_back({l, m, r});
    }
    sort(v.rbegin(), v.rend());
    for(auto [l, i, r]: v){
        if(i == m){
            tree.set(r, tree.get(r, r) + 1);
        }
        else{
            res[i] = tree.get(l, r);
        }
    }
    return res;
}

vector<ll> sumDistinctValues(ll n, 
        vector<ll> &c, 
        vector<pair<ll, ll>> &ranges, 
        vector<ll> &f,
        vector<vector<ll>> &ind){

    ll m = ranges.size();
    vector<ll> res(m);

    vector<tuple<ll, ll, ll>> v;
    for(ll i = 0; i < m; ++i){
        ll l, r;
        tie(l, r) = ranges[i];
        v.push_back({l, r, i});
    }

    SegmentTree tree(n + 1);
    for(ll col = 1; col <= n; ++col){
        reverse(ind[col].begin(), ind[col].end());
        ind[col].pop_back();
        tree.set(ind[col].back(), f[col]);
    }

    ll k = 1;

    sort(v.begin(), v.end());
    for(auto [l, r, i]: v){
        while(k < l){
            tree.set(k, 0);
            ind[c[k]].pop_back();
            tree.set(ind[c[k]].back(), f[c[k]]);
            ++k;
        }
        res[i] = tree.get(l, r);
    }

    return res;
}
 
void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> c(n + 1);
    for(ll i = 1; i <= n; ++i){
        cin >> c[i];
    }

    vector<ll> l(m + 1), r(m + 1);
    for(ll i = 1; i <= m; ++i){
        cin >> l[i] >> r[i];
    }

    vector<vector<ll>> color_ind(n + 1);
    for(ll i = 0; i <= n; ++i){
        color_ind[i].push_back(0);
    }
    for(ll i = 1; i <= n; ++i){
        color_ind[c[i]].push_back(i);
    }
    for(ll i = 0; i <= n; ++i){
        color_ind[i].push_back(n + 1);
    }

    vector<pair<ll, ll>> queries;
    vector<vector<ll>> query_indices(n + 1);

    for(ll col = 1; col <= n; ++col){
        for(ll i = 1; i < (ll)color_ind[col].size(); ++i){
            query_indices[col].push_back(queries.size());
            queries.push_back({color_ind[col][i - 1] + 1, color_ind[col][i] - 1});
        }
    }

    vector<pair<ll, ll>> ranges;
    for(ll i = 1; i <= m; ++i){
        ranges.push_back({l[i], r[i]});
    }

    vector<ll> res = numberOfIntersectingRanges(n + 1, queries, ranges);

    vector<ll> f(n + 1);
    for(ll col = 1; col <= n; ++col){
        for(ll ind: query_indices[col]){
            f[col] += res[ind];
        }
    }

    for(ll elem: sumDistinctValues(n, c, ranges, f, color_ind)){
        cout << elem << ' ';
    }
    cout << '\n';

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
 
