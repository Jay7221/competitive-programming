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

#define ti tuple<int, int, int>
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> mat(n, vector<bool>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            bool tmp;
            cin >> tmp;
            mat[i][j] = tmp;
        }
    }
    int sx, sy, dx, dy, rx, ry;
    cin >> sx >> sy;
    cin >> dx >> dy;
    cin >> rx >> ry;

    vector<pair<int, int>> diff = {
        {   rx ,   ry  }, 
        {   ry ,   -rx },
        {   -rx,   -ry },
        {   -ry,   rx  }
    };

    vector<vector<int>> dist(n, vector<int>(m, INF));
    dist[sx][sy] = 0;

    priority_queue<ti, vector<ti>, greater<ti>> pq;
    pq.push({dist[sx][sy], sx, sy});

    auto check = [&](int x, int y){
        return ((x >= 0) && (y >= 0) && (x < n) && (y < m) && (!mat[x][y]));
    };

    while(!pq.empty()){
        int d, x, y;
        tie(d, x, y) = pq.top();
        pq.pop();

        if(d > dist[x][y]){
            continue;
        }

        for(auto pr: diff){
            int dx, dy;
            tie(dx, dy) = pr;
            int xx = x + dx;
            int yy = y + dy;
            if(check(xx, yy) && (dist[xx][yy] > dist[x][y] + 1)){
                dist[xx][yy] = dist[x][y] + 1;
                pq.push({dist[xx][yy], xx, yy});
            }
        }
    }


    cout << dist[dx][dy] << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
