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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(n + 1);
    dp[0].push_back(0);

    for(int i = 1; i <= n; ++i){
        priority_queue<tuple<int, int, int>> pq;
        pq.push({a[1][i], -1, 0});
        for(int j = 0; j < i - 1; ++j){
            pq.push({dp[j][0] + a[j + 2][i], j, 0});
        }
        pq.push({dp[i - 1][0], i - 1, 0});

        while(!pq.empty() && ((int)dp[i].size() < k)){
            int val, ind, num;
            tie(val, ind, num) = pq.top();
            pq.pop();
            dp[i].push_back(val);

            if((ind > -1) && (num + 1 < (int)dp[ind].size())){
                if(ind < i - 1){
                    pq.push({dp[ind][num + 1] + a[ind + 2][i], ind, num + 1});
                }
                else{
                    pq.push({dp[ind][num + 1], ind, num + 1});
                }
            }
        }
    }

    for(int ans: dp[n]){
        cout << ans << ' ';
    }
    cout << '\n';
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
 
