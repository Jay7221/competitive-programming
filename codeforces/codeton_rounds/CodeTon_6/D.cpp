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

  cin >> n;
  vector<int> c(n + 1);
  for(int i = 1; i <= n; ++i){
    cin >> c[i];
  }
  cin >> k;

  vector<int> v;
  for(int i = 1; i <= n; ++i){
    while(!v.empty()){
      int ind = v.back();
      if(c[ind] < c[i]){
        break;
      }
      v.pop_back();
    }

    v.push_back(i);
  }

  vector<int> moves(n + 1);

  for(int ind : v){
    moves[ind] = k / c[ind];
    k %= c[ind];
  }

  int m = v.size();
  for(int i = 0; i < m - 1; ++i){
    int ind1 = v[i];
    int ind2 = v[i + 1];
    int diff = c[ind2] - c[ind1];
    int transfer = k / diff;
    transfer = min(transfer, moves[ind1]);
    moves[ind1] -= transfer;
    moves[ind2] += transfer;
    k -= transfer * diff;
  }


  for(int i = n; i >= 1; --i){
    moves[i - 1] += moves[i];
  }
  for(int i = 1; i <= n; ++i){
    cout << moves[i] << ' ';
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
 
