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
 
 
bool solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> a(n + 1, vector<ll>(m + 1));
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }

    vector<vector<bool>> type(n + 1, vector<bool>(m + 1));
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= m; ++j){
            char ch;
            cin >> ch;
            type[i][j] = (ch == '1');
        }
    }

    vector<vector<ll>> pre(n + 1, vector<ll>(m + 1));
    for(ll i = 1; i <= n; ++i){
        ll curRow = 0;
        for(ll j = 1; j <= m; ++j){
            curRow += type[i][j];
            pre[i][j] = pre[i - 1][j] + curRow;
        }
    }

    auto sum = [&](ll i, ll j, ll x, ll y){
        return (pre[x][y] + pre[i][j] - pre[x][j] - pre[i][y]);
    };

    ll diff = 0;
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= m; ++j){
            if(type[i][j]){
                diff += a[i][j];
            }
            else{
                diff -= a[i][j];
            }
        }
    }
    diff = abs(diff);

    ll d = 0;
    for(ll i = k; i <= n; ++i){
        for(ll j = k; j <= m; ++j){
            ll coin = sum(i - k, j - k, i, j);
            coin = abs(k * k - 2 * coin);
            if(coin){
                d = gcd(d, coin);
            }
        }
    }

    if(diff > 0){
        if(d > 0){
            return (diff % d == 0);
        }
        else{
            return false;
        }
    }
    else{
        return true;
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        if(solve()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}
 
