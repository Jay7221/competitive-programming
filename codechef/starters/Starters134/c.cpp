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
 
const int MAX  = 1e9 + 7;

#define t3i tuple<int, int, int>
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; ++i){
        cin >> grid[i];
    }

    vector<vector<int>> min_dist(n, vector<int>(m, MAX));
    priority_queue<t3i, vector<t3i>, greater<t3i>> pq;

    for(int i = 0; i < n; ++i){
        if(min_dist[i][0] == MAX){
            min_dist[i][0] = (grid[i][0] == '1');
            pq.push({min_dist[i][0], i, 0});
        }
        if(min_dist[i][m - 1] == MAX){
            min_dist[i][m - 1] = (grid[i][m - 1] == '1');
            pq.push({min_dist[i][m - 1], i, m - 1});
        }
    }
    for(int j = 0; j < m; ++j){
        if(min_dist[0][j] == MAX){
            min_dist[0][j] = (grid[0][j] == '1');
            pq.push({min_dist[0][j], 0, j});
        }
        if(min_dist[n - 1][j] == MAX){
            min_dist[n - 1][j] = (grid[n - 1][j] == '1');
            pq.push({min_dist[n - 1][j], n - 1, j});
        }
    }

    vector<pair<int, int>> delta = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    auto check = [&](int x, int y){
        return ((x >= 0) && (x < n) && (y >= 0) && (y < m));
    };

    while(!pq.empty()){
        int dist, x, y;
        tie(dist, x, y) = pq.top();
        pq.pop();

        if(dist != min_dist[x][y]){
            continue;
        }

        for(auto [dx, dy]: delta){
            int nx = x + dx, ny = y + dy;
            if(check(nx, ny)){
                int new_dist = dist + (grid[nx][ny] == '1');
                if(min_dist[nx][ny] > new_dist){
                    min_dist[nx][ny] = new_dist;
                    pq.push({min_dist[nx][ny], nx, ny});
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == '0'){
                ans = max(ans, min_dist[i][j]);
            }
        }
    }

    cout << ans << '\n';
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
 
