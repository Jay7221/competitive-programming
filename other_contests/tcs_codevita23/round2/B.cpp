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
 
const int INF = 1e9 + 7;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> traffic(n, vector<int>(m));
    vector<vector<int>> dist(n, vector<int>(m, INF));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> traffic[i][j];
        }
    }
    int sx, sy;
    int dx, dy;
    cin >> sx >> sy;
    cin >> dx >> dy;

    --sx, --sy;
    --dx, --dy;

    dist[sx][sy] = traffic[sx][sy];

    for(int i = sx; i < n; ++i){
        for(int j = sy; j < m; ++j){
            if(i + 1 < n){
                dist[i + 1][j] = min(dist[i + 1][j], traffic[i + 1][j] + dist[i][j]);
            }
            if(j + 1 < m){
                dist[i][j + 1] = min(dist[i][j + 1], traffic[i][j + 1] + dist[i][j]);
            }
        }
    }

    if(dist[dx][dy] == INF){
        cout << -1;
    }
    else{
        cout << dist[dx][dy];
    }

}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
