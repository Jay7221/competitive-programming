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
 
 
int findMinimumEqualSum(vector<int> rowA, vector<int> rowB){
  int n = rowA.size();
  int m = rowB.size();
  int sumA = accumulate(rowA.begin(), rowA.end(), 0);
  int sumB = accumulate(rowB.begin(), rowB.end(), 0);
  int zeroA = count(rowA.begin(), rowA.end(), 0);
  int zeroB = count(rowB.begin(), rowB.end(), 0);
  if(min(zeroA, zeroB) > 0){
    return max(sumA + zeroA, sumB + zeroB);
  }
  if((zeroA == 0) && (zeroB == 0)){
    if(sumA == sumB){
      return sumA;
    }
    return -1;
  }
  if(zeroA == 0){
    if(sumA < sumB + zeroB){
      return -1;
    }
    return sumA;
  }
  if(zeroB == 0){
    if(sumB < sumA + zeroA){
      return -1;
    }
    return sumB;
  }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  for(int i = 0; i < m; ++i){
    cin >> b[i];
  }
  cout << findMinimumEqualSum(a, b) << '\n';
 
    
    return 0;
}
 
