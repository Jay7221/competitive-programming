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
 
 
struct DSU{
    vector<map<int, int>> freq;
    vector<int> par, rank;
    DSU(int n){
        freq = vector<map<int, int>>(n);
        par = vector<int>(n);
        rank = vector<int>(n, 1);
        for(int i = 0; i < n; ++i){
            par[i] = i;
        }
    }
    int get_par(int ind){
        if(par[ind] == ind){
            return ind;
        }
        return par[ind] = get_par(par[ind]);
    }
    void add(int ind, int val){
        ind = get_par(ind);
        ++freq[ind][val];
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
        for(auto [k, f] : freq[v]){
            freq[u][k] += f;
        }
    }
    int query(int x, int y){
        x = get_par(x);
        return freq[x][y];
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    DSU dsu(n + 1);
    for(int i = 1; i <= n; ++i){
        int a;
        cin >> a;
        dsu.add(i, a);
    }
    while(q--){
        int type;
        cin >> type;
        int a, b;
        cin >> a >> b;
        if(type == 1){
            dsu.merge(a, b);
        }
        else{
            cout << dsu.query(a, b) << '\n';
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
