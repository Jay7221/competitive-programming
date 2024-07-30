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
 
const int MOD = 1e9 + 7;
int mult(int a, int b){
    return ((a * 1ll * b) % MOD);
}
int power(int a, int p){
    int ans = 1;
    while(p > 0){
        if(p & 1){
            ans = mult(ans, a);
        }
        a = mult(a, a);
        p >>= 1;
    }
    return ans;
}
int divide(int a, int b){
    return mult(a, power(b, MOD - 2));
}
const int MAX = 2e5 + 7;
vector<int> fact(MAX);
void pre(){
    fact[0] = 1;
    for(int i = 1; i < MAX; ++i){
        fact[i] = mult(fact[i - 1], i);
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        dsu.merge(u, v);
    }
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    map<int, vector<int>> components;
    for(int i = 0; i < n; ++i){
        int id = dsu.get_par(i);
        components[id].push_back(a[i]);
    }
    int ans = fact[n];
    for(auto [id, comp]: components){
        int c = comp.size();
        ans = divide(ans, fact[c]);

        map<int, int> freq;
        for(int a : comp){
            ++freq[a];
        }
        for(auto [a, f] : freq){
            ans = mult(ans, fact[f]);
        }
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    pre();
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
