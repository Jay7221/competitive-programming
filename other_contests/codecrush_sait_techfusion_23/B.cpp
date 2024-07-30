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
 
vector<vector<ll>> get_number_of_rectangles(vector<vector<int>> &a, int n, int m){
    vector<vector<ll>> dp(n, vector<ll>(m));
    vector<vector<ll>> h(n, vector<ll>(m, 1));

    for(int i = 1; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(a[i - 1][j] == a[i][j]){
                h[i][j] += h[i - 1][j];
            }
        }
    }

    for(int i = 0; i < n; ++i){
        vector<int> indices;
        for(int j = 0; j < m; ++j){
            int k = -1;
            while(!indices.empty()){
                int col = indices.back();
                if((a[i][col] != a[i][j]) || (h[i][col] < h[i][j])){
                    break;
                }
                indices.pop_back();
            }
            if(!indices.empty()){
                k = indices.back();
            }
            dp[i][j] += h[i][j] * (j - k);
            if(k != -1){
                if(a[i][k] == a[i][j]){

                    dp[i][j] += dp[i][k];
                }
            }
            indices.push_back(j);
        }
    }

    return dp;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> dp = get_number_of_rectangles(a, n, m);
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            ans += dp[i][j];
        }
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    tc = 1;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
