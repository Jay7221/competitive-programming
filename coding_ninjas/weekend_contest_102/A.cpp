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
 
 
void add(int x, vector<int> &fact){
   vector<int> primes = {2, 3, 5, 7};
   for(int p : primes){
      while(x % p == 0){
         x /= p;
         fact.push_back(p);
      }
   }
}
int goodSpell(int n, string &s) {
    bool z1 = false, z2 = false;
    for(int i = 0; i < n / 2; ++i){
        z1 |= (s[i] == '0');
        z2 |= (s[i + n/2] == '0');
    }
   if(z1 && z2){
      return 1;
   }
   if(z1 || z2){
      return 0;
   }
   vector<int> a1, a2;
   for(int i = 0; i < n / 2; ++i){
      add(s[i] - '0', a1);
      add(s[i + n/2] - '0', a2);
   }
   sort(a1.begin(), a1.end());
   sort(a2.begin(), a2.end());
   return (a1 == a2);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        int n;
        string s;
        cin >> n >> s;
        cout << goodSpell(n, s) << '\n';
    }
    
    return 0;
}
 
