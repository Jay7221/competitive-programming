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
 
struct ModInt{
    int val;
    const int MOD = 1e9 + 7;

    ModInt(){
        val = 0;
    }

    void operator=(ModInt x){
        val = x.val;
        val = (val % MOD);
    }
    void operator+=(ModInt x){
        val = (val + 0ll + x.val) % MOD;
    }
    void operator-=(ModInt x){
        val = (((val + 0ll - x.val) % MOD + MOD) % MOD);
    }
    void operator*=(ModInt x){
        val = (val * 1ll * x.val) % MOD;
    }
    void operator/=(ModInt x){
        int p = MOD - 2;
        while(p > 0){
            if(p & 1){
                val = (val * 1ll * x.val) % MOD;
            }
            p >>= 1;
            x.val = (x.val * 1ll * x.val) % MOD;
        }
    }


    template<typename T>
    void operator=(T x){
        val = x;
        val = (val % MOD);
    }
    template<typename T>
    void operator+=(T x){
        val = (val + 0ll + x) % MOD;
    }
    template<typename T>
    void operator-=(T x){
        val = (((val + 0ll - x) % MOD + MOD) % MOD);
    }
    template<typename T>
    void operator*=(T x){
        val = (val * 1ll * x) % MOD;
    }
    template<typename T>
    void operator/=(T x){
        int p = MOD - 2;
        while(p > 0){
            if(p & 1){
                val = (val * 1ll * x) % MOD;
            }
            p >>= 1;
            x = (x * 1ll * x) % MOD;
        }
    }
    friend istream& operator>>(istream& in, ModInt &m){
        in >> m.val;
        return in;
    }
    friend ostream& operator<<(ostream& out, const ModInt m){
        out << m.val;
    /*
    for(int a = 1; a < 1000; ++a){
      for(int b = 1; b < 1000; ++b){
        if(a == ((m.val * 1ll * b) % m.MOD)){
          out << "(" << a << ", " << b << ")" ;
          return out;
        }
      }
    }
    */
        return out;
    }
    template<typename T>
    friend ModInt operator+(ModInt a, T b){
        ModInt res = a;
        res += b;
        return res;
    }
    template<typename T>
    friend ModInt operator-(ModInt a, T b){
        ModInt res = a;
        res -= b;
        return res;
    }
    template<typename T>
    friend ModInt operator*(ModInt a, T b){
        ModInt res = a;
        res *= b;
        return res;
    }
};

ModInt power(ModInt a, int p){
  ModInt ans;
  ans = 1;
  while(p > 0){
    if(p & 1){
      ans *= a;
    }
    a *= a;
    p >>= 1;
  }
  return ans;
}
 
void solve() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<ModInt> dp(n + 1);
  for(int i = 1; i <= n; ++i){
    dp[i] = n / i;
    dp[i] /= n;
    dp[i] = power(dp[i], k);
  }
  for(int i = n; i > 0; --i){
    for(int j = 2 * i; j <= n; j += i){
      dp[i] -= dp[j];
    }
  }
  for(int i = 1; i <= n; ++i){
    dp[i] += dp[i - 1];
  }
  while(q--){
    int l, r;
    cin >> l >> r;
    --l;
    cout << (dp[r] - dp[l]) << '\n';
  }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    
    return 0;
}
 
