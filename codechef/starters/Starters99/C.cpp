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
 
const ll INF = 1e15 + 7;
 
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i];
    }
    multiset<ll> mins, maxs;
    for(int i = 0; i < n; ++i){
        mins.insert(min(a[i], b[i]));
        maxs.insert(max(a[i], b[i]));
    }
    ll ans = INF;
    auto get = [&](ll x){
        // returns the possible answer if x were the max element
        ll ans = x - *(--mins.end());
        if(maxs.upper_bound(x) != maxs.begin()){
            ans = min(ans, x - *(--maxs.upper_bound(x)));
        }
        if(ans < 0){
            ans = INF;
        }
        return ans;
    };
    for(int i = 0; i < n; ++i){
        mins.erase(mins.find(min(a[i], b[i])));
        maxs.erase(maxs.find(max(a[i], b[i])));

        ans = min(ans, get(a[i]));
        ans = min(ans, get(b[i]));

        mins.insert(min(a[i], b[i]));
        maxs.insert(max(a[i], b[i]));
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
 
