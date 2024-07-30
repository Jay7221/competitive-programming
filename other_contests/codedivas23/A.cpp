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
 
const int LOGMAX = 20;
const int MAX = 1e5 + 7;
vector<vector<int>> par(MAX, vector<int>(LOGMAX, -1));
int getPar(int u, int level){
    for(int k = 0; k < LOGMAX; ++k){
        if(1 & (level >> k)){
            if(par[u][k] == -1){
                return -1;
            }
            u = par[u][k];
        }
    }
    return u;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<bool> vis(n);
    for(int i = 0; i < n; ++i){
        cin >> par[i][0];
    }
    for(int p = 1; p < LOGMAX; ++p){
        for(int i = 0; i < n; ++i){
            if(par[i][p - 1] != -1){
                par[i][p] = par[par[i][p - 1]][p - 1];
            }
        }
    }
    vector<int> ans;
    for(int i = 0; i < k; ++i){
        int node;
        cin >> node;
        int l = 0, r = n;
        while(l < r){
            int m = (l + r + 1) / 2;
            int p = getPar(node, m);
            if((p == -1) || (vis[p])){
                r = m - 1;
            }
            else{
                l = m;
            }
        }
        node = getPar(node, l);
        vis[node] = true;
        ans.push_back(node);
    }
    for(int elem : ans){
        cout << elem << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
