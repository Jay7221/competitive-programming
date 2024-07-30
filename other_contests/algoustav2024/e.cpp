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
 
const int LOGMAX = 30;
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> par(n, vector<int>(LOGMAX));
    vector<int> depth(n);
    for(int i = 0; i < n; ++i){
        for(int k = 0; k < LOGMAX; ++k){
            par[i][k] = i;
        }
    }
    auto lcs = [&](int u, int v){
        if(depth[u] < depth[v]){
            swap(u, v);
        }
        int diff = depth[u] - depth[v];
        for(int k = 0; k < LOGMAX; ++k){
            if(1 & (diff >> k)){
                v = par[v][k];
            }
        }
        if(u == v){
            return u;
        }
        for(int k = LOGMAX - 1; k >= 0; --k){
            if(par[u][k] != par[v][k]){
                u = par[u][k];
                v = par[v][k];
            }
        }
        return par[u][0];
    };
    while(q--){
        int type, u, v;
        cin >> type >> u >> v;
        --u, --v;
        if(type == 1){
            par[v][0] = u;
            for(int k = 1; k < LOGMAX; ++k){
                par[v][k] = par[par[v][k - 1]][k - 1];
            }
            depth[v] = depth[u] + 1;
        }
        else{
            if(lcs(u, v) == u){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
