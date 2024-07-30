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
        int sz;
        DSU(){
            n = 0;
        }
        DSU(int n){
            this -> n = n;
            sz = 0;
            par = vector<int>(n, -1);
            rank = vector<int>(n, 1);
        }
        void put(int u){
            par[u] = u;
            ++sz;
        }
        bool get(int u){
            return (par[u] != -1);
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
            --sz;
        }
        int size(){
            return sz;
        }
};
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    map<int, vector<int>> indices;
    for(int i = 1; i <= n; ++i){
        indices[a[i]].push_back(i);
    }

    DSU dsu(n + 2);
    vector<bool> good(n + 2);

    int rem = n;
    
    for(auto [v, ind]: indices){
        if(dsu.size() < rem){
            for(int i: ind){
                good[i] = true;
            }
        }
        for(int i: ind){
            --rem;
            dsu.put(i);
            if(dsu.get(i - 1)){
                dsu.merge(i, i - 1);
            }
            if(dsu.get(i + 1)){
                dsu.merge(i, i + 1);
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        cout << good[i];
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
 
