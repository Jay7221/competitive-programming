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
    friend ostream& operator<<(ostream& out, ModInt &m){
        out << m.val;
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


 
void solve() {
    int a, b;
    cin >> a >> b;
    int n = a;
    int m = 2 * a + 7;
    vector<ModInt> fact(m);
    fact[0] = 1;
    for(int i = 1; i < m; ++i){
        fact[i] = i;
        fact[i] *= fact[i - 1];
    }
    auto get = [&](int i, int j){
        ModInt ans = fact[i + j];
        ans /= fact[i];
        ans /= fact[j];
        return ans;
    };
    int k = a / 2;
    ModInt ans;
    ans = 0;
    for(int i = k + b + 1; i < n; ++i){
        int j = k - b - 1;
        ModInt val = get(i, j);
        if(i > k + b + 1){
            val -= get(i - 1, j);
        }
        int x = n - 1 - i;
        int y = n - 1 - j;
        val *= get(x, y);
        ans += val;
        cerr << i << ' ' << j << " : " << val << '\n';
    }
    ans *= 2;
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}
 
