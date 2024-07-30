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
 
 
const ll MOD = 1e9 + 7;

void dfs(int k, vector<vector<bool>> &grid, map<pair<int, int>, int> &points){
    int rem = 0;
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < k; ++j){
            rem += grid[i][j];
        }
    }
    rem = k - rem;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    auto check = [&](int x, int y){
        return ((x >= 0) && (y >= 0) && (x < n) && (y < m));
    };
    map<pair<int, int>, int> points;
    vector<vector<bool>> grid(k, vector<bool>(k));
    grid[0][0] = true;
    dfs(k, grid, points);
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            for(auto [pr, w] : points){
                int dx, dy;
                tie(dx, dy) = pr;
                int x = i + dx, y = j + dy;
                if(check(x, y)){
                    ans = (ans + w) % MOD;
                }
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
 
