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
#define pll pair<ll, ll>
 
#define PI 3.1415926535897932384626433832795l 

// -------------------------<rng>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
const ll INF = 1e18 + 7;
 
void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<vector<ll>> a(n, vector<ll>(m));
    vector<vector<ll>> dp(n, vector<ll>(m, INF));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }
    vector<vector<bool>> active(n, vector<bool>(m));
    auto check = [&](int x, int y){
        return ((x >= 0) && (y >= 0) && (x < n) && (y < m));
    };
    auto activate = [&](int i, int j){
        active[i][j] = true;
        for(int dx = -1; dx <= 1; ++dx){
            for(int dy = -1; dy <= 1; ++dy){
                if(abs(dx) + abs(dy) != 1){
                    continue;
                }
                int x = i + dx, y = j + dy;
                if(check(x, y)){
                    a[x][y] += k;
                }
            }
        }
    };
    auto deactivate = [&](int i, int j){
        active[i][j] = false;
        for(int dx = -1; dx <= 1; ++dx){
            for(int dy = -1; dy <= 1; ++dy){
                if(abs(dx) + abs(dy) != 1){
                    continue;
                }
                int x = i + dx, y = j + dy;
                if(check(x, y)){
                    a[x][y] -= k;
                }
            }
        }
    };


    vector<string> s(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
        for(int j = 0; j < m; ++j){
            if(s[i][j] == '1'){
                activate(i, j);
            }
        }
    }
    dp[0][0] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({dp[0][0], 0});

    while(!pq.empty()){
        ll d, ind;
        tie(d, ind) = pq.top();
        pq.pop();
        int x, y;
        x = ind / m;
        y = ind % m;
        if(dp[x][y] > d){
            continue;
        }

        for(int dx = -1; dx <= 1; ++dx){
            for(int dy = -1; dy <= 1; ++dy){
                if(abs(dx) + abs(dy) != 1)
                    continue;
                int xx = x + dx, yy = y + dy;
                if(!check(xx, yy)){
                    continue;
                }
                ll new_cost = dp[x][y] + a[xx][yy] - common_goose(x, y, xx, yy) * k;
                if(dp[xx][yy] > dp[x][y] + a[xx][yy]){
                    dp[xx][yy] = dp[x][y] + a[xx][yy];
                    pq.push({dp[xx][yy], xx * m + yy});
                }
            }
        }
    }
    for(int i = 0; i < n ; ++i){
        cerr << dp[i] << '\n';
    }
    cerr << "-------------------\n";
    cout << dp[n - 1][m - 1] << '\n';
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
 
