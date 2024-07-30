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
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m));
    for(long long i = 0; i < n; ++i){
        for(long long j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }
    vector<vector<long long>> h(n, vector<long long>(m, 1));
    for(long long i = 0; i < n; ++i){
        for(long long j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }
    for(long long i = 1; i < n; ++i){
        for(long long j = 0; j < m; ++j){
            if(a[i][j] == a[i - 1][j]){
                h[i][j] += h[i - 1][j];
            }
        }
    }
    long long ans = 0;
    for(long long i = 0; i < n; ++i){
        vector<tuple<long long, long long, long long>> v;
        long long cur = 0;
        for(long long j = 0; j < m; ++j){
            long long jind = j;
            while(!v.empty()){
                long long ind, height, val;
                tie(ind, height, val) = v.back();
                if((a[i][ind] == a[i][j]) && (height < h[i][j])){
                    break;
                }
                v.pop_back();
                cur -= val;
                if(a[i][ind] == a[i][j]){
                    jind = ind;
                }
            }
            long long val = (j + 1 - jind) * h[i][j];
            v.push_back((tuple<long long, long long, long long>){jind, h[i][j], val});
            cur += val;
            ans += cur;
        }
    }
    cout << ans << '\n';


    /*
    for(int l = 0; l < n; ++l){
        for(int r = l; r < n; ++r){
            int len = r - l + 1;
            vector<int> dp(m);
            for(int i = 0; i < m; ++i){
                dp[i] = (h[r][i] >= len);
            }
            for(int i = 1; i < m; ++i){
                if(dp[i] > 0){
                    if(a[r][i] == a[r][i - 1]){
                        dp[i] += dp[i - 1];
                    }
                }
            }
            int cur = accumulate(dp.begin(), dp.end(), 0);
            ans += cur;
        }
    }
    */

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
 
