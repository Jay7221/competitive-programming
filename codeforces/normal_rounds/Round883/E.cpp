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
 
#define ar array
#define ll __int128
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
 
#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
 
// -------------------------<RNG>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
 
const ll MAX = 1e18 + 7;
const ll MAXK = 1e6 + 1;
map<ll, bool> isPossible;
void pre(){
    for(ll k = 2; k < MAXK; ++k){
        ll flake = k * k;
        ll sum = k * k + k + 1;
        for(; sum < MAX && flake < MAX; flake *= k, sum += flake){
            isPossible[sum] = true;
        }
    }
}
void solve() {
    long long n;
    cin >> n;
    bool flag = isPossible[n];
    if(!flag){
        auto get = [&](ll k){
            return (1 + k + k * k);
        };
        ll l = 2, r = 1e9 + 7;
        while(l < r){
            ll mid = (l + r) / 2;
            if(get(mid) < n){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        flag = (get(l) == n);
    }
    if(flag){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
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
 
