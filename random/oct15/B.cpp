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
 
 
int solution(vector<int> A, int N){
    int n = N;
    if(n < 2){
        return 0;
    }
    auto get = [&](int cost){
        vector<vector<bool>> dp(n, vector<bool>(n));
        dp[0][n - 1] = true;
        int ans = n;
        for(int len = n; len > 1; --len){
            for(int l = 0, r = len - 1; r < n; ++l, ++r){
                if(!dp[l][r]){
                    continue;
                }
                if(A[l] + A[l + 1] == cost){
                    dp[l + 2][r] = true;
                    ans = len - 2;
                }
                if(A[l] + A[r] == cost){
                    dp[l + 1][r - 1] = true;
                    ans = len - 2;
                }
                if(A[r] + A[r - 1] == cost){
                    dp[l][r - 2] = true;
                    ans = len - 2;
                }
            }
        }
        ans = n - ans;
        ans /= 2;
        return ans;
    };

    return max({get(A[0] + A[n - 1]), get(A[0] + A[1]), get(A[n - 2] + A[n - 1])});
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    cout << solution(a, n) << '\n';
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
 
