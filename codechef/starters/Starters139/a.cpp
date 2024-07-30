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
 
 
void solve() {
    int n;
    ll c;
    cin >> n >> c;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int ans = n;

    ll tot = accumulate(a.begin(), a.end(), 0ll);
    ll prev = 0;

    if(a[0] * (tot - a[0]) <= c){
        cout << 1 << '\n';
        return;
    }

    vector<bool> vis(n);
    vector<pair<ll, int>> v;
    for(int i = 1; i < n; ++i){
        v.push_back({a[i] * (tot - prev) - a[i] * a[i], i});
    }
    sort(v.rbegin(), v.rend());

    while(!v.empty()){
        int ind;
        ll val;
        tie(val, ind) = v.back();
        if(val > c){
            break;
        }

        c -= val;
        prev += a[ind];
        tot -= a[ind];
        vis[ind] = true;
        --ans;

        v.clear();
        for(int i = 1; i < n; ++i){
            if(!vis[i]){
                v.push_back({a[i] * (tot - prev) - a[i] * a[i], i});
            }
        }
        sort(v.rbegin(), v.rend());
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
 
