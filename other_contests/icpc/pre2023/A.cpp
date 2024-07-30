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

const int mod = 1e9 + 7;
ll powr(ll a, ll b){
    ll res = 1;
    while(b){
        if (b & 1) res *= a, res %= mod;
        a *= a;
        a %= mod;
        b = b >> 1;
    }
    return res;
}
//modular arithmatic
ll addm(ll a,ll b){
    return (a + b) % mod;
}

ll subm(ll a,ll b){
    return ((a - b) %mod + mod) % mod;
}

ll mulm(ll a,ll b){
    return ((a % mod) * (b % mod)) % mod;
}

ll divm(ll a,ll b){
    return mulm(a, powr(b, mod - 2));
}
//inverse
ll inv(ll x){
    return powr(x, mod - 2);
}

const int MAX_N = 151;
const int MAX_BALLS = 61;
const int MAX_WICKETS = 11;
const int X = 102;
const int STRIKE = 3;

ll dp[MAX_N][MAX_BALLS][MAX_WICKETS][X][STRIKE];
ll inv6 = inv(6);

ll memo(int n, int b, int w, int x, int strike){
    x = min(x, 100);
    if((n <= 0) && (x >= 100)){
        return 1;
    }
    if(n <= 0){
        return 0;
    }
    if(w >= 10){
        return 0;
    }
    if(b == 0){
        return 0;
    }

    if(dp[n][b][w][x][strike] != -1){
        return dp[n][b][w][x][strike];
    }



    ll ans = 0;

    bool overEnd = ((b - 1) % 6 == 0);

    for(int run : {1, 2, 3, 4, 6}){
        bool flip = (run & 1);
        int next_strike = (strike == 2) ? strike : (strike ^ flip ^ overEnd);
        int new_x = (strike == 1) ? (x + run) : x;
        ans += memo(n - run, b - 1, w, new_x, next_strike);
    }
    if((strike == 1) && (x >= 100)){
        ans += memo(n, b - 1, w + 1, x, 2);
    }
    else if(strike != 1){
        int next_strike = (strike == 2) ? strike : (strike ^ overEnd);
        ans += memo(n, b - 1, w + 1, x, next_strike);
    }

    ans = mulm(ans, inv6);

    return dp[n][b][w][x][strike] = ans;
} 

void solve(){
   ll n, b, w, x;
    cin >> n >> b >> w >> x;
    cout << memo(n,b,w,x,1) << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    memset(dp, -1, sizeof(dp));
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
