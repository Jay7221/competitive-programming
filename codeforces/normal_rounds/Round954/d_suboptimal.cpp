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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int dp0[n][n];
    int dp1[n][n];
    // dp0[i][j] = no sign left
    // dp1[i][j] = one sign left
    memset(dp0, 0, sizeof dp0);
    memset(dp1, 0, sizeof dp1);

    for(int i = 0; i < n; ++i){
        dp0[i][i] = s[i] - '0';
    }
    for(int i = 1; i < n; ++i){
        dp1[i - 1][i] = 10 * dp0[i - 1][i - 1] + dp0[i][i];
    }

    for(int len = 2; len <= n; ++len){
        for(int i = 0, j = len - 1; j < n; ++i, ++j){
            dp0[i][j] = dp0[i][i] + dp0[i + 1][j];
            for(int k = i; k < j; ++k){
                dp0[i][j] = min(dp0[i][j], dp0[i][k] + dp0[k + 1][j]);
                dp0[i][j] = min(dp0[i][j], dp0[i][k] * dp0[k + 1][j]);
            }
        }
    }

    for(int len = 3; len <= n; ++len){
        for(int i = 0, j = len - 1; j < n; ++i, ++j){
            dp1[i][j] = dp0[i][i] + dp1[i + 1][j];
            for(int k = i; k < j; ++k){
                if(k + 1 < j){
                    dp1[i][j] = min(dp1[i][j], dp0[i][k] + dp1[k + 1][j]);
                    dp1[i][j] = min(dp1[i][j], dp0[i][k] * dp1[k + 1][j]);
                }
                if(i < k){
                    dp1[i][j] = min(dp1[i][j], dp1[i][k] + dp0[k + 1][j]);
                    dp1[i][j] = min(dp1[i][j], dp1[i][k] * dp0[k + 1][j]);
                }
            }
        }
    }

    cout << dp1[0][n - 1] << '\n';
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
 
