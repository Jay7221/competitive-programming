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
 
#include <atcoder/modint>
using namespace atcoder;

using mint = modint998244353;

mint power(mint a, int b){
    mint res = 1;
    while(b){
        if(b & 1){
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}
 
void solve() {
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    --a1, --a2, --a3;

    mint l, r;
    mint k, t = 0;
    if(
        (a3 <= a2 + 1)
        ||
        (a1 >= a3)
    ){
        l = power(10, a1);
        l = power(10, a1);
        k = 0;
    }
    else{
        l = power(10, a3) - power(10, a2 + 1);
        k = power(10, a2 + 1) - power(10, a2);
    }

    if(
        (a3 + 1 > a2)
        &&
        (a1 < a3)
    ){
        r = power(10, a1 + 1) - 1;
    }
    else{
        r = power(10, a3 + 1) - power(10, a2);
    }

    cerr << l.val() << ' ' << r.val() << '\n';
    cerr << k.val() << ' ' << t.val() << '\n';


    /*
    l = max(power(10, a1), power(10, a3) - power(10, a2 + 1));
    r = min(
        power(10, a1 + 1) - 1,
        power(10, a3 + 1) - power(10, a2)
    );
    k = power(10, a3) - l - power(10, a2);
    t = power(10, a2 + 1) - power(10, a3 + 1) + r;
    k = max(k, 0);
    t = max(t, 0);
    */
    mint ans = (r - l + 1) * (power(10, a2 + 1) - power(10, a2)) + ((k * (k + 1)) / 2) - ((t * (t + 1)) / 2);
    cout << ans.val() << '\n';
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
 
