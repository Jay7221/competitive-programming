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
 
const ll INF = 1e18 + 7;
 
void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<ll> l(n), r(n);
    stack<pair<ll, ll>> st;

    st.push({INF, -1});
    for(ll i = 0; i < n; ++i){
        while(st.top().first <= a[i]){
            st.pop();
        }
        l[i] = st.top().second;
        st.push({a[i], i});
    }

    while(!st.empty()){
        st.pop();
    }

    st.push({INF, n});
    for(ll i = n - 1; i >= 0; --i){
        while(st.top().first < a[i]){
            st.pop();
        }
        r[i] = st.top().second;
        st.push({a[i], i});
    }

    vector<ll> next(n);
    vector<ll> ind(n, n);
    for(ll i = n - 1; i >= 0; --i){
        next[i] = ind[a[i]];
        ind[a[i]] = i;
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i){
        ans += (a[i] + 1) * (r[i] - i) * (i - l[i]);
    }
    for(ll i = 0; i < n; ++i){
        ans -= (i + 1) * (next[i] - i);
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
 
