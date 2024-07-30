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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, -1), b(m + 1, -1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= m; ++i){
        cin >> b[i];
    }
    int k;
    cin >> k;

    vector<vector<int>> pre(n + 2, vector<int>(m + 2));
    vector<vector<int>> suf(n + 2, vector<int>(m + 2));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            pre[i][j] = max({
                pre[i - 1][j],
                pre[i][j - 1],
                pre[i - 1][j - 1] + (a[i] == b[j])
            });
        }
    }
    for(int i = n; i > 0; --i){
        for(int j = m; j > 0; --j){
            suf[i][j] = max({
                suf[i + 1][j],
                suf[i][j + 1],
                suf[i + 1][j + 1] + (a[i] == b[j])
            });
        }
    }
    int ans = -1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if((a[i] == b[j]) && (a[i] == k)){
                ans = max(ans, 1 + 2 * min(pre[i - 1][j - 1], suf[i + 1][j + 1]));
            }
        }
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
