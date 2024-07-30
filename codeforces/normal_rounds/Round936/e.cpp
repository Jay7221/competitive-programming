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
    ModInt(int x){
        val = (x % MOD + MOD) % MOD;
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
        assert(x.val >= 0);
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

const int MAX = 2e5 + 7;
vector<ModInt> fact(MAX);
void pre(){
    fact[0] = 1;
    for(int i = 1; i < MAX; ++i){
        fact[i] = i * fact[i - 1];
    }
}

ModInt com(int a, int b){
    ModInt ans = 0;
    if(a >= b){
        ans = 1;
        ans *= fact[a];
        ans /= fact[a - b];
        ans /= fact[b];
    }
    return ans;
}

 
void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<int> pre(m1), suf(m2);
    for(int i = 0; i < m1; ++i){
        cin >> pre[i];
    }
    for(int i = 0; i < m2; ++i){
        cin >> suf[i];
    }

    int p = pre.back(), s = suf.front();
    bool flag = true;
    flag &= (p == s);
    flag &= (s == n) || (m2 > 1);
    flag &= (p == 1) || (m1 > 1);
    flag &= (pre.front() == 1);
    flag &= (suf.back() == n);

    if(!flag){
        cout << 0 << '\n';
        return;
    }


    // Remove the largest element
    --p;
    s = n - s;

    ModInt ans = com(n - 1, p);

    reverse(pre.begin(), pre.end());
    for(int i = 1; i < m1; ++i){
        // Remove the largest element to be place at pre[i]
        --p;
        int b = pre[i - 1] - pre[i] - 1;
        // Remove b smaller elements to be placed between pre[i] to pre[i - 1]
        ans *= com(p, b);
        ans *= fact[b];
        p -= b;
    }

    for(int i = 1; i < m2; ++i){
        --s;
        int b = suf[i] - suf[i - 1] - 1;
        ans *= com(s, b);
        ans *= fact[b];
        s -= b;
    }

    cout << ans.val << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    pre();
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
