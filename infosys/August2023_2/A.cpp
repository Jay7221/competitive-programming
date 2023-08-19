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
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    // dp[i][j][ch] = max length of lcs in s1[:i], s2[:j] ending in character ch
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(10, 0)));
    vector<vector<bool>> isValid(10, vector<bool>(10, true));
    for(int i = 1; i < q; ++i){
        int c0 = s3[i - 1] - '0';
        int c1 = s3[i] - '0';
        isValid[c0][c1] = false;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int c1 = s1[i - 1] - '0';
            int c2 = s2[j - 1] - '0';
            for(int ch = 0; ch < 10; ++ch){
                dp[i][j][ch] = max({dp[i][j][ch], dp[i - 1][j][ch], dp[i][j - 1][ch]});
                if(c1 == c2){
                    int c = c1;
                    if(isValid[ch][c]){
                        dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j - 1][ch] + 1);
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int ch = 0; ch < 10; ++ch){
        ans = max(dp[n][m][ch], ans);
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
