#include <bits/stdc++.h>
 
using namespace std;
 
//#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename A, typename B, typename C> ostream& operator<<(ostream &os, const tuple<A, B, C> &p) { A a; B b; C c; tie(a, b, c) = p; return os << '(' << a << ", " << b << ", " << c << ')'; }
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
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        a[i] %= 3;
    }
    vector<tuple<int, int, int>> d;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            for(int k = 0; k < 3; ++k){
                if((i + j + k) % 3 == 0){
                    d.push_back({i, j, k});
                }
            }
        }
    }
    auto cost = [&](int a, int b){
        // cost of convert a to b mod 3 by incrementing
        if(b < a){
            return ((3 + b) - a);
        }
        return (b - a);
    };
    vector<vector<int>> dp(n, vector<int>(9));
    for(auto [x, y, z] : d){
        int state = 3 * y + z;
        dp[1][state] = cost(a[0], y) + cost(a[1], z);
    }
    for(int i = 2; i < n; ++i){
        for(auto [x, y, z]: d){
            int prev_state = 3 * x + y;
            int state = 3 * y + z;
            dp[i][state] = dp[i - 1][prev_state] + cost(a[i], z);
        }
    }
    int ans = *min_element(dp[n - 1].begin(), dp[n - 1].end());
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
 
