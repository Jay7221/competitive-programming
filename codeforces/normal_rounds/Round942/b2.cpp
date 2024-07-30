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
 
const int MAX = 2e6 + 7;
vector<int> sp(MAX, 1);
void pre(){
    vector<vector<int>> divisors(MAX);
    for(int i = 2; i < MAX; ++i){
        for(int j = 1; i * j < MAX; ++j){
            divisors[i * j].push_back(i);
        }
    }
    for(int p = 2; p < MAX; ++p){
        if(sp[p] == 1){
            for(int j = 1; j * p < MAX; ++j){
                sp[j * p] = p;
            }
        }
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    for(int a = 1; a * a <= n; ++a){
        for(int b = 1; b * b <= m; ++b){
            if(gcd(a, b) == 1){
                ans += min(n / a, m / b) / (a + b);
            }
        }
    }
    cout << ans << '\n';
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
 
