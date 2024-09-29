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
 
 
template < int MOD = 998244353, typename T = int > struct ModInt {

    T val;

    ModInt(T V = 0) : val(V) { val %= MOD; }

    ModInt& operator += (const ModInt& rhs) {
        if ((val += rhs.val) >= MOD) val -= MOD;
        return *this;
    }
    ModInt& operator += (const T rhs) {
        if ((val += rhs) >= MOD) val -= MOD;
        return *this;
    }

    ModInt& operator -= (const ModInt& rhs) { 
        if ((val += MOD - rhs.val) >= MOD) val -= MOD; 
        return *this; 
    }
    ModInt& operator -= (const T rhs) { 
        if ((val += MOD - rhs) >= MOD) val -= MOD; 
        return *this; 
    }

    ModInt& operator *= (const ModInt& rhs) { val = (1ll * val * rhs.val) % MOD; return *this; }
    ModInt& operator *= (const T rhs) { val = (1ll * val * rhs) % MOD; return *this; }

    ModInt& operator /= (const ModInt& rhs) { return *this *= rhs.inverse(); }
    ModInt& operator /= (const T rhs) { return *this *= ModInt(rhs).inverse(); }

    ModInt& operator %= (const ModInt& rhs) { val %= rhs.val; return *this; }
    ModInt& operator %= (const T rhs) { val %= rhs; return *this; }

    ModInt& operator ++() { return *this += 1; }
    ModInt& operator --() { return *this -= 1; }
 
    ModInt operator ++(T unused) { ModInt res(*this); ++*this; return res; }
    ModInt operator --(T unused) { ModInt res(*this); --*this; return res; }
    
    ModInt operator + (const ModInt& rhs) const { ModInt res(*this); return res += rhs; }
    ModInt operator + (const T rhs) const { ModInt res(*this); return res += rhs; }

    ModInt operator % (const ModInt& rhs) const { ModInt res(*this); return res %= rhs; }
    ModInt operator % (const T rhs) const { ModInt res(*this); return res %= rhs; }

    ModInt operator - (const ModInt& rhs) const { ModInt res(*this); return res -= rhs; }
    ModInt operator - (const T rhs) const { ModInt res(*this); return res -= rhs; }

    ModInt operator * (const ModInt& rhs) const { ModInt res(*this); return res *= rhs; }
    ModInt operator * (const T rhs) const { ModInt res(*this); return res *= rhs; }

    ModInt operator / (const ModInt& rhs) const { ModInt res(*this); return res /= rhs; }
    ModInt operator / (const T rhs) const { ModInt res(*this); return res /= rhs; }

    ModInt& operator = (const ModInt& rhs) { val = rhs.val; return *this; }
    ModInt& operator = (const T rhs) { val = rhs; return *this; }

    T operator ~ () { return ~val; }
    bool operator ! () { return !val; }

    bool operator == (const ModInt& rhs) const { return val == rhs.val; }
    bool operator == (const T rhs) const { return val == rhs; }

    bool operator != (const ModInt& rhs) const { return val != rhs.val; }
    bool operator != (const T rhs) const { return val != rhs; }

    bool operator < (const ModInt& rhs) const { return val < rhs.val; }
    bool operator < (const T rhs) const { return val < rhs; }

    bool operator <= (const ModInt& rhs) const { return val <= rhs.val; }
    bool operator <= (const T rhs) const { return val <= rhs; }

    bool operator > (const ModInt& rhs) const { return val > rhs.val; }
    bool operator > (const T rhs) const { return val > rhs; }

    bool operator >= (const ModInt& rhs) const { return val >= rhs.val; }
    bool operator >= (const T rhs) const { return val >= rhs; }

    T operator () () const { return val; }

    ModInt inverse() const { return power(MOD - 2); }

    ModInt power(T n) const {
        ModInt a = *this, res = 1;
        while (n > 0) {
            if (n & 1) res *= a;
            a *= a, n >>= 1;
        }
        return res;
    }

    ModInt power(ModInt n) const {
        ModInt a = *this, res = 1;
        T e = n();
        while (e > 0) {
            if (e & 1) res *= a;
            a *= a, e >>= 1;
        }
        return res;
    }

    friend ModInt operator ^ (ModInt rhs, T n) { return rhs.power(n); }
    friend ModInt operator ^ (ModInt rhs, ModInt n) { return rhs.power(n); }

    friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept { return is >> x.val; }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }

};


const int MOD = 998244353;
typedef ModInt<MOD> modint;

static const int MAX = 4e5 + 7;
vector<modint> fact(MAX);
vector<modint> inv(MAX);
vector<modint> invFact(MAX);

modint com(ll a, ll b){
    if(a < b){
        return 0;
    }
    if(b < 0){
        return 0;
    }
    return (fact[a] / (fact[a - b] * fact[b]));
}
void pre(){
    fact[0] = 1;
    fact[1] = 1;
    inv[1] = 1;
    invFact[0] = 1;
    invFact[1] = 1;
    for(int i = 2; i < MAX; ++i){
        ll q = MOD / i;
        ll r = MOD % i;
        inv[i] = modint(-q) * inv[r];
        fact[i] = modint(i) * fact[i - 1];
        invFact[i] = inv[i] * invFact[i - 1];
    }
}

int type(int elem, int n){
    return (elem == 0 ? 0 : ((elem <= n) ? 1 : 2));
}

modint numberPairs(vector<pair<int, int>> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int fix1 = 0;
    int fix2 = 0;

    for(int i = 0; i < n / 2; ++i){
        fix1 += (arr[i].second == 1);       // fixed element
    }
    for(int i = n / 2; i < n; ++i){
        fix2 += (arr[i].second == 1);       // fixed element
    }

    modint res = 0;

    for(int j = 0; j <= min(fix1, fix2); ++j){
        if(j & 1){
            res -= (com(fix1, j) * com(fix2, j) * fact[j]) * fact[n / 2 - j];
        }
        else{
            res += (com(fix1, j) * com(fix2, j) * fact[j]) * fact[n / 2 - j];
        }
    }

    return res;
}

modint power(int a, int p){
    modint res = 1;
    modint cur = a;
    while(p){
        if(p & 1){
            res *= cur;
        }
        cur *= cur;
        p >>= 1;
    }
    return res;
}

modint solve() {
    int n;
    cin >> n;
    vector<int> p(2 * n);
    for(int i = 0; i < 2 * n; ++i){
        cin >> p[i];
    }


    vector<pair<int, int>> arr;
    // {elem, 0} -> no present in p
    // {elem, 1} -> present in p, that is fixed => cannot be paired with another fixed

    vector<bool> vis(2 * n + 1);
    for(int elem: p){
        vis[elem] = true;
    }

    for(int elem = 1; elem <= 2 * n; ++elem){
        if(!vis[elem]){
            arr.push_back({elem, 0});
        }
    }

    int numFreePairs = 0;

    for(int i = 0; i < 2 * n; i += 2){
        int t1 = type(p[i], n);
        int t2 = type(p[i + 1], n);

        if((t1 == 0) && (t2 == 0)){
            ++numFreePairs;
            continue;
        }

        if((t1 != 0) && (t2 != 0)){
            // can't be changed
            continue;
        }

        if(t1 != 0){
            arr.push_back({p[i], 1});
        }
        if(t2 != 0){
            arr.push_back({p[i + 1], 1});
        }
    }

    modint res = power(2, numFreePairs) * fact[numFreePairs] * numberPairs(arr);
    return res;

}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    pre();
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        cout << solve() << '\n';
    }
    
    return 0;
}
 
