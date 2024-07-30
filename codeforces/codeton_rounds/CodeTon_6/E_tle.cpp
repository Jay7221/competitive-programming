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
 
 
const int XOR_MAX = (1 << 13);
void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  vector<vector<int>> mex(n + 1, vector<int>(n + 1));

  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }

  vector<vector<int>> change(n + 1);
  for(int i = 1; i <= n; ++i){

    vector<bool> vis(XOR_MAX);
    int cur = 0;

    for(int j = i; j <= n; ++j){
      vis[a[j]] = true;
      bool flag = false;
      while(vis[cur]){
        ++cur;
        flag = true;
      }

      if(flag){
        change[j].push_back(i);
      }
      mex[i][j] = cur;
    }
  }

  vector<vector<bool>> dp(n + 1, vector<bool>(XOR_MAX));
  dp[0][0] = true;

  for(int i = 1; i <= n; ++i){
    for(int x = 0; x < XOR_MAX; ++x){
      dp[i][x] = (dp[i][x] | dp[i - 1][x]);
    }
    for(int l : change[i]){
      for(int x = 0; x < XOR_MAX; ++x){
        int new_x = x ^ mex[l][i];
        dp[i][new_x] = (dp[i][new_x] | dp[l - 1][x]);
      }
    }
  }

  int ans = 0;
  for(int x = 0; x < XOR_MAX; ++x){
    if(dp[n][x]){
      ans = x;
    }
  }
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
 
