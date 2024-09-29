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
 
vector<vector<bool>> update_dp(vector<vector<bool>> &dp, vector<vector<int>> &matrix, int val){
    int n = dp.size();
    int m = dp[0].size();

    // calc dp[i][j] = is there a true in matrix (i, j) to (n - 1, m - 1)

    for(int i = n - 1; i >= 0; --i){
        for(int j = m - 1; j >= 0; --j){
            if(i + 1 < n){
                dp[i][j] = dp[i][j] | dp[i + 1][j];
            }
            if(j + 1 < m){
                dp[i][j] = dp[i][j] | dp[i][j + 1];
            }
        }
    }

    vector<vector<bool>> ndp(n, vector<bool>(m));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            ndp[i][j] = (matrix[i][j] == val);
            if((i + 1 < n) && (j + 1 < m)){
                ndp[i][j] = (ndp[i][j] & !dp[i + 1][j + 1]);
            }
        }
    }

    return ndp;
}
 
bool solve() {
    int l, n, m;
    cin >> l >> n >> m;

    vector<int> a(l);
    for(int i = 0; i < l; ++i){
        cin >> a[i];
    }

    vector<vector<int>> b(n, vector<int>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> b[i][j];
        }
    }

    int max_moves = min({8, n * m, l});
    vector<vector<bool>> dp(n, vector<bool>(m));
    for(int i = max_moves - 1; i >= 0; --i){
        dp = update_dp(dp, b, a[i]);
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(dp[i][j]){
                return true;
            }
        }
    }

    return false;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        if(solve()){
            cout << "T\n";
        }
        else{
            cout << "N\n";
        }
    }
    
    return 0;
}
 
