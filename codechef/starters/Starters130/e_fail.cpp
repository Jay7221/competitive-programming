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
 
const int MAX = 3e6 + 7;
vector<int> primes;
vector<int> f(MAX);
void pre(){
    vector<bool> isPrime(MAX, true);
    vector<int> smallest_div(MAX);
    for(int i = 2; i < MAX; ++i){
        if(isPrime[i]){
            ++f[i];
            smallest_div[i] = i;
            primes.push_back(i);
            for(int j = 2; i * j < MAX; ++j){
                isPrime[i * j] = false;
                if(smallest_div[i * j] == 0){
                    smallest_div[i * j] = i;
                }
            }
        }
    }
    for(int i = 2; i < MAX; ++i){
        f[i] = f[smallest_div[i]] + f[i / smallest_div[i]];
    }
}
 
void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    ll sum = 0;

    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
        a[i] = f[a[i]];
    }
    sort(a.rbegin(), a.rend());

    ll ans = sum - a[0] - a[1];
    ll diff = 1000;
    for(ll x = m; x >= max(1ll, m - diff); --x){
        ans = max(
            ans, 
            sum + k * x - ( max(a[0], f[x]) + max(a[1], f[x]) )
        );
    }
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
 
