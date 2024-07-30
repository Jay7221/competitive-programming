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
const int MAX = 1e6 + 7;

vector<int> dp(MAX);
vector<vector<int>> factors(MAX);

void pre_primes(){
    vector<bool> isPrime(MAX, true);
    for(int i = 2; i < MAX; ++i){
        if(isPrime[i]){
            factors[i].push_back(i);
            for(int j = 2; i * j < MAX; ++j){
                isPrime[i * j] = false;
                factors[i * j].push_back(i);
            }
        }
    }
    for(int i = 4; i < MAX; i += 4){
        factors[i].push_back(4);
    }
}
ll c(ll i, ll j){
    if(j == 4){
        return (2 * (i / j)) % 4;
    }
    return ((j - 1) * (i / j)) % j;
}
void pre(){
    pre_primes();
    ll cur = 0;
    for(int n = 2; n < MAX; ++n){
        dp[n] = dp[n - 1];
        for(int p: factors[n]){
            cur = (cur - c(n - 1, p) + MOD) % MOD;
            cur = (cur + c(n, p)) % MOD;
        }
        dp[n] = (dp[n] + cur) % MOD;
    }
}
void solve() {
    int n;
    cin >> n;
    cout << dp[n] << '\n';
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
 
