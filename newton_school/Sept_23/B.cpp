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
 
 
ll solve() {
  int n;
  cin >> n;
  vector<int> x1(n), y1(n), x2(n), y2(n);
  for(int i = 0; i < n; ++i){
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
  }

  int x_low = *max_element(x1.begin(), x1.end());
  int y_low = *max_element(y1.begin(), y1.end());

  int x_high = *min_element(x2.begin(), x2.end());
  int y_high = *min_element(y2.begin(), y2.end());

  ll dx = x_high - x_low;
  ll dy = y_high - y_low;
  dx = max(dx, 0ll);
  dy = max(dy, 0ll);
  return (dx * dy);

}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

  cout << solve();
    
    return 0;
}
 
