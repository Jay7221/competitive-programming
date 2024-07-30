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
 
vector<ll> palindromes;
const ll MAX = 1e10 * 7;
void pre(){
    for(int i = 1; i < 10; ++i){
        palindromes.push_back(i);
    }
    for(int i = 1; i < sqrt(MAX); ++i){
        string s = to_string(i);
        string srev = s;
        reverse(srev.begin(), srev.end());
        palindromes.push_back(stol(s + srev));
        for(int d = 0; d < 10; ++d){
            string fill;
            fill.push_back('0' + d);
            palindromes.push_back(stol(s + fill + srev));
        }
        stoi(s);
    }
    sort(palindromes.begin(), palindromes.end());
}
 
ll solve() {
    ll n;
    cin >> n;
    ll x = *lower_bound(palindromes.begin(), palindromes.end(), (n << 2));
    return (x - n);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    pre();

    int tc;
    cin >> tc;
    ll ans = 0;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
            ans ^= solve();
    }
    cout << ans << '\n';
    
    return 0;
}
 
