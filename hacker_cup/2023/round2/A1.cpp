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

 
int n, m;
vector<vector<char>> board;
vector<vector<bool>> vis;
vector<pair<int, int>> d = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
 
bool check(int i, int j){
    return ((i >= 0) && (j >= 0) && (i < n) && (j < m));
}
int noPieces = 0;
vector<pair<int, int>> dfs(int i, int j){
    ++noPieces;
    vis[i][j] = true;
    vector<pair<int, int>> open;
    for(auto [dx, dy] : d){
        int x = i + dx;
        int y = j + dy;
        if(check(x, y)){
            if(board[x][y] == '.'){
                open.push_back({x, y});
            }
            else if(board[x][y] == 'W' && !vis[x][y]){
                for(auto p : dfs(x, y)){
                    open.push_back(p);
                }
            }
        }
    }
    return open;
}
void solve() {
    cin >> n >> m;
    board.assign(n, vector<char>(m));
    vis.assign(n, vector<bool>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> board[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(board[i][j] != 'W'){
                continue;
            }
            if(vis[i][j]){
                continue;
            }
            noPieces = 0;
            vector<pair<int, int>> open = dfs(i, j);
            sort(open.begin(), open.end());
            open.resize(unique(open.begin(), open.end()) - open.begin());
            if(open.size() == 1){
                ans = max(ans, noPieces);
            }
        }
    }
    if(ans > 0){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}
 
