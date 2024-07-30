#include <bits/stdc++.h>
 
using namespace std;
 
//#pragma gcc optimize("ofast,unroll-loops") 
//#pragma gcc target("avx,avx2,avx512,fma") 
 
template<typename a, typename b> ostream& operator<<(ostream &os, const pair<a, b> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename t_container, typename t = typename enable_if<!is_same<t_container, string>::value, typename t_container::value_type>::type> ostream& operator<<(ostream &os, const t_container &v) { os << '{'; string sep; for (const t &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename head, typename... tail> void dbg_out(head h, tail... t) { cerr << ' ' << h; dbg_out(t...); }
#ifdef local
#define dbg(...) cerr << "(" << #__va_args__ << "):", dbg_out(__va_args__)
#else
#define dbg(...)
#endif
 
#define ll long long
#define ld long double
 
#define pi 3.1415926535897932384626433832795l 

// -------------------------<rng>------------------------- 
// random number generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());  
#define shuf(v) shuffle(all(v), rng); 
// use mt19937_64 for 64 bit random numbers.
 
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for(ll l1 = 0, l2 = 0, r = 1; r < n; ++r){
        while((a[r] - a[l1]) > (r - l1 + 1)){
            ++l1;
        }
        while((a[r] - a[l2]) >= (r - l2 + 1)){
            ++l2;
        }
        ans += l2 - l1;
        if(l2 < r){
            ll d = r - l2 - 1;
            ans += (d * (d + 1)) / 2;
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
//        cout << "# case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
