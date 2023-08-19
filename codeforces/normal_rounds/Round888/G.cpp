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
 
 
struct Edge{
    int s, t;
    ll w;
};
struct Query{
    int id, s, t;
    ll val;
    bool ans;
};
class DSU{
    public:
        vector<int> par;
        vector<int> rank;
        int n;
        DSU(){
            n = 0;
        }
        DSU(int n){
            this -> n = n;
            par = vector<int>(n);
            for(int i = 0; i < n; ++i){
                par[i] = i;
            }
            rank = vector<int>(n, 1);
        }
        int get_par(int u){
            if(par[u] == u){
                return u;
            }
            return par[u] = get_par(par[u]);
        }
        void merge(int u, int v){
            u = get_par(u);
            v = get_par(v);
            if(u == v){
                return;
            }
            if(rank[u] < rank[v]){
                swap(u, v);
            }
            par[v] = u;
            rank[u] += rank[v];
            --n;
        }
        int size(){
            return n;
        }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> h(n);
    for(int i = 0; i < n; ++i){
        cin >> h[i];
    }
    vector<Edge> edges(m);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[i].s = u;
        edges[i].t = v;
        edges[i].w = max(h[u], h[v]);
    }
    int q;
    cin >> q;
    vector<Query> query(q);
    for(int i = 0; i < q; ++i){
        int a, b, e;
        cin >> a >> b >> e;
        --a, --b;
        query[i].s = a;
        query[i].t = b;
        query[i].val = h[a] + e;
        query[i].id = i;
    }
    sort(edges.begin(), edges.end(),
            [](Edge a, Edge b){
            return (a.w < b.w);
            }
        );
    sort(query.begin(), query.end(), 
            [](Query a, Query b){
            return (a.val < b.val);
            }
        );
    DSU dsu(n);
    int pos = 0;
    for(int i = 0; i < q; ++i){
        while((pos < m) && (edges[pos].w <= query[i].val)){
            dsu.merge(edges[pos].s, edges[pos].t);
            ++pos;
        }
        query[i].ans = (dsu.get_par(query[i].s) == dsu.get_par(query[i].t));
    }
    sort(query.begin(), query.end(), 
            [](Query a, Query b){
            return (a.id < b.id);
            }
        );
    for(int i = 0; i < q; ++i){
        if(query[i].ans){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
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
 
