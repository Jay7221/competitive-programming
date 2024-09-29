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
        val = (x % MOD);
    }

    void operator=(int x){
        val = x;
        val = (val % MOD);
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

vector<int> a;
vector<vector<int>> adj;
vector<vector<ModInt>> dp;

void dfs(int u){
    for(int v: adj[u]){
        dfs(v);
        dp[u][0] += dp[v][0];
        dp[u][1] += dp[v][1];
    }
    dp[u][a[u]] += dp[u][1 - a[u]];
    dp[u][a[u]] += 1;
}

void solve() {
    int n;
    cin >> n;

    a = vector<int>(n);
    adj = vector<vector<int>>(n);
    dp = vector<vector<ModInt>>(n, vector<ModInt>(2));

    for(int i = 0; i < n; ++i){
        cin >> a[i];
        --a[i];
    }

    for(int i = 1; i < n; ++i){
        int p;
        cin >> p; 
        --p;
        adj[p].push_back(i);
    }

    dfs(0);

    ModInt res = 0;
    for(int u = 0; u < n; ++u){
        ModInt no0 = dp[u][0];
        ModInt no1 = dp[u][1];
        for(int ch: adj[u]){
            no0 -= dp[ch][0];
            no1 -= dp[ch][1];
            if(a[u] == 0){
                no0 -= dp[ch][1];
            }
            else{
                no1 -= dp[ch][0];
            }

            res += dp[ch][0] * no1 + dp[ch][1] * no0;
        }
    }

    cout << res << '\n';
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
 
