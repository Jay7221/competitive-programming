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
  vector<bitset<XOR_MAX>> dp(n + 1);

  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }

  dp[0][0] = 1;

  vector<int> left(XOR_MAX), right(XOR_MAX);
  for(int r = 1; r <= n; ++r){
    vector<bool> vis(XOR_MAX);
    vector<int> mexes;
    // v = {l, x}
    int mex = 0;
    for(int l = r; l >= 1; --l){
      vis[a[l]] = true;

      while(vis[mex]){
        ++mex;
      }

      if((left[mex] < l) && (right[mex] < r)){
        mexes.push_back(mex);
        left[mex] = l;
        right[mex] = r;
      }

    }
    dp[r] |= dp[r - 1];
    for(int x = 0; x < XOR_MAX; ++x){
      for(int mex : mexes){
        int l = left[mex];
        int new_x = (x ^ mex);
        if(dp[l - 1][x]){
          dp[r][new_x] = 1;
        }
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
        solve();
    }
    
    return 0;
}
 
