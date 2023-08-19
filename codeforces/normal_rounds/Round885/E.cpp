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
 
ll MOD; 
struct ModInt{
    ll val;

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
    template<typename T>
    friend ModInt operator/(ModInt a, T b){
        ModInt res = a;
        res /= b;
        return res;
    }
};

vector<pair<ll, ll>> odd_factorize(ll x){
    vector<pair<ll, ll>> ans;
    while(!(x & 1)){
        x >>= 1;
    }
    for(ll i = 3; i * i <= x; ++i){
        if(x % i == 0){
            ll cnt = 0;
            while(x % i == 0){
                ++cnt;
                x /= i;
            }
            ans.push_back({i, cnt});
        }
    }
    if(x > 1){
        ans.push_back({x, 1});
    }
    return ans;
}
void solve() {
    ll x, q, M;
    cin >> x >> q >> M;
    MOD = M;
    vector<ll> xq(q);
    for(int i = 0; i < q; ++i){
        cin >> xq[i];
    }
    ModInt ans;
    ans = 1;
    map<ll, ll> freq;
    ll cnt_zero = 0;
    for(auto [p, f] : odd_factorize(x)){
        if((freq[p] + 1) % MOD == 0){
            --cnt_zero;
        }
        else{
            ans /= freq[p] + 1;
        }
        freq[p] += f;
        if((freq[p] + 1) % MOD == 0){
            ++cnt_zero;
        }
        else{
            ans *= freq[p] + 1;
        }
    }
    for(auto x : xq){
        for(auto [p, f] : odd_factorize(x)){
            if((freq[p] + 1) % MOD == 0){
                --cnt_zero;
            }
            else{
                ans /= freq[p] + 1;
            }
            freq[p] += f;
            if((freq[p] + 1) % MOD == 0){
                ++cnt_zero;
            }
            else{
                ans *= freq[p] + 1;
            }
        }
        if(cnt_zero > 0){
            cout << 0 << '\n';
        }else{
            cout << ans << '\n';
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 

