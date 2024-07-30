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
 
 
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> grid(n);
    for(int i = 0; i < n; ++i){
        cin >> grid[i];
    }
    vector<vector<int>> d(n, vector<int>(m, n + m + 2));
    queue<pair<int, int>> point_que;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == 'v'){
                d[i][j] = 0;
                point_que.push({i, j});
            }
        }
    }
    auto check = [&](int x, int y){
        return ((x >= 0) && (y >= 0) && (x < n) && (y < m));
    };
    while(!point_que.empty()){
        int x, y;
        tie(x, y) = point_que.front();
        point_que.pop();
        for(int dx = -1; dx <= 1; ++dx){
            for(int dy = -1; dy <= 1; ++dy){
                if(abs(dx) + abs(dy) != 1){
                    continue;
                }
                int xx = x + dx;
                int yy = y + dy;
                if(check(xx, yy) && (d[xx][yy] > d[x][y] + 1)){
                    d[xx][yy] = d[x][y] + 1;
                    point_que.push({xx, yy});
                }
            }
        }
    }
    vector<vector<bool>> onPath;
    auto print = [&](vector<vector<bool>> &a){
        for(auto v : a){
            cerr << v << '\n';
        }
        cerr << "------------\n";
    };
    auto isEnclosed = [&](){
        vector<vector<bool>> vis(n, vector<bool>(m));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == '#'){
                    vis[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        bool enclosed = true;
        while(!q.empty()){
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            for(int dx = -1; dx <= 1; ++dx){
                for(int dy = -1; dy <= 1; ++dy){
                    int xx = x + dx;
                    int yy = y + dy;
                    if(!check(xx, yy)){
                        enclosed = false;
                    }
                    else if(!vis[xx][yy] && !onPath[xx][yy]){
                        vis[xx][yy] = true;
                        q.push({xx, yy});
                    }
                }
            }
        }
        return enclosed;
    };
    auto isPossible = [&](int val, int x, int y){
        onPath = vector<vector<bool>>(n, vector<bool>(m));
        queue<pair<int, int>> q;
        q.push({x, y});
        onPath[x][y] = true;
        while(!q.empty()){
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            for(int dx = -1; dx <= 1; ++dx){
                for(int dy = -1; dy <= 1; ++dy){
                    if(abs(dx) + abs(dy) != 1){
                        continue;
                    }
                    int xx = x + dx;
                    int yy = y + dy;
                    if(check(xx, yy) && (d[xx][yy] >= val) && (grid[xx][yy] != '#') && !onPath[xx][yy]){
                        onPath[xx][yy] = true;
                        q.push({xx, yy});
                    }
                }
            }
        }
        return isEnclosed();
    };
    while(q--){
        int x, y;
        cin >> x >> y;
        --x, --y;
        int l = 0, r = d[x][y];
        while(l < r){
            int m = (l + r + 1) / 2;
            if(isPossible(m, x, y)){
                l = m;
            }
            else{
                r = m - 1;
            }
        }
        cout << l << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
