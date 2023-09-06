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
 
 
const int MAX = 1e6 + 7;
vector<bool> isPrime;
// isPrime[i] = 1 => i has 1 or 0 prime factors
void pre(){
    isPrime.assign(MAX, true);
    for(int i = 2; i < MAX; ++i){
        if(isPrime[i]){
            for(int j = 2; i * j < MAX; ++j){
                isPrime[i * j] = false;
            }
        }
    }
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    vector<int> pre = a, suf = a;
    for(int i = 1; i <= n + 1; ++i){
        pre[i] = gcd(pre[i], pre[i  - 1]);
    }
    for(int i = n; i >= 0; --i){
        suf[i] = gcd(suf[i], suf[i + 1]);
    }
    bool flag = true;
    for(int i = 1; i <= n; ++i){
        if(isPrime[gcd(pre[i - 1], suf[i + 1])]){
            flag = false;
        }
    }
    if(flag){
        cout << "BOB\n";
    }
    else{
        cout << "DRAW\n";
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
 
