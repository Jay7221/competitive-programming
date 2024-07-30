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
 
vector<ll> fact, inv, invFact;
const int MAX = 5e5 + 7;
const int MOD = 1e9 + 7;

ll add(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return ((a + b) % MOD);
}
ll sub(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return (((a - b) % MOD + MOD) % MOD);
}
ll mult(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
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
void pre(){
    fact = vector<ll>(MAX);
    inv= vector<ll>(MAX);
    invFact = vector<ll>(MAX);
    fact[0] = fact[1] = inv[1] = invFact[0] = invFact[1] = 1;
    for(int i = 2; i < MAX; ++i){
        ll q = MOD / i;
        ll r = MOD % i;
        inv[i] = mult(-q, inv[r]);
        fact[i] = mult(i, fact[i - 1]);
        invFact[i] = mult(inv[i], invFact[i - 1]);
    }
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


 
int solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));

    int k = (n * (n + 1)) / 2;
    vector<bool> vis(n * n + 1);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }

    if(n == 1){
        return 1;
    }

    int l = (n * (n - 1)) / 2 + 1;
    int r = (n * (n + 1)) / 2;

    ll no_p = 0, no_diag = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(a[i][j] == 0){
                continue;
            }
            if(i == j){
                if((a[i][j] < l) || (r < a[i][j])){
                    return 0;
                }
            }
            else{
                if((l <= a[i][j]) && (a[i][j] <= r)){
                    return 0;
                }
                if(a[j][i] == 0){
                    int req = (a[i][j] > k) ? (a[i][j] - k) : (a[i][j] + k);
                    if(vis[req]){
                        return 0;
                    }
                }
                else{
                    if(abs(a[i][j] - a[j][i]) != k){
                        return 0;
                    }
                }

                vis[a[i][j]] = true;
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= i; ++j){
            if(i == j){
                if(a[i][j] == 0){
                    ++no_diag;
                }
            }
            else{
                if((a[i][j] == 0) && (a[j][i] == 0)){
                    ++no_p;
                }
            }
        }
    }

    return mult(mult(fact[no_diag], fact[no_p]), power(2, no_p));
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
 
