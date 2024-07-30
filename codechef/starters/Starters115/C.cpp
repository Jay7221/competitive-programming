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
 
const ll MOD = 1e9 + 7;
const int MAX = 2e6 + 7;
vector<ll> fact;
ll add(ll a, ll b){
    return ((a + b) % MOD);
}
ll sub(ll a, ll b){
    return (((a - b) % MOD + MOD) % MOD);
}
ll mult(ll a, ll b){
    return ((a * b) % MOD);
}
ll power(ll a, ll p){
    a = ((a % MOD) + MOD) % MOD;
    ll ans = 1;
    while(p > 0){
        if(p & 1){
            ans = mult(ans, a);
        }
        a = mult(a, a);
        p >>= 1;
    }
    return ans;
}
ll divide(ll a, ll b){
    return mult(a, power(b, MOD - 2));
}
ll com(ll a, ll b){
    if(a < b){
        return 0;
    }
    return divide(fact[a], mult(fact[a - b], fact[b]));
}
void pre(){
    fact = vector<ll>(MAX);
    fact[0] = fact[1] = 1;
    for(int i = 2; i < MAX; ++i){
        fact[i] = mult(i, fact[i - 1]);
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }
    if(n == 1){
        cout << 1 << '\n';
        return;
    }
    auto update = [&](string a, string b){
        int a1 = count(a.begin(), a.end(), '1');
        int b1 = count(b.begin(), b.end(), '1');
        int int1 = 0;
        for(int i = 0; i < m; ++i){
            int1 += ((a[i] == b[i]) && (a[i] == '1'));
        }
        if(int1 == 0){
            return a;
        }
        if((a1 < 2) || (b1 < 2)){
            return a;
        }
        for(int i = 0; i < m; ++i){
            if(b[i] == '1'){
                a[i] = '1';
            }
        }
        return a;
    };
    for(int i = n - 2; i > 0; --i){
        s[i] = update(s[i], s[i + 1]);
    }
    int swap1= count(s[1].begin(), s[1].end(), '1');
    int cnt1 = 0;
    for(int i = 0; i < m; ++i){
        cnt1 += ((s[1][i] == '1') && (s[0][i] == '1'));
    }
    ll ans = com(swap1, cnt1);
    cout << ans << '\n';
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
 
