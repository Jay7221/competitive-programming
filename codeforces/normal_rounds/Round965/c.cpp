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
 
const ll INF = 2e9 + 7;
 
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(ll i = 0; i < n; ++i){
        cin >> b[i];
    }

    vector<ll> a0, a1;
    for(ll i = 0; i < n; ++i){
        if(b[i] == 0){
            a0.push_back(a[i]);
        }
        else{
            a1.push_back(a[i]);
        }
    }

    ll m = a1.size();

    sort(a0.begin(), a0.end());
    sort(a1.begin(), a1.end());

    vector<ll> pre1 = a1;
    for(ll i = 1; i < m; ++i){
        pre1[i] += pre1[i - 1];
    }

    auto sum1 = [&](ll l, ll r){
        return pre1[r] - ((l > 0) ? pre1[l - 1] : 0);
    };

    auto check = [&](ll x, ll i){
        ll nc0 = lower_bound(a0.begin(), a0.end(), x) - a0.begin();
        nc0 = (n - m) - nc0;
        if((a[i] >= x) && (b[i] == 0)){
            --nc0;
        }

        ll nc1 = lower_bound(a1.begin(), a1.end(), x) - a1.begin();
        nc1 = m - nc1;
        if((a[i] >= x) && (b[i] == 1)){
            --nc1;
        }

        ll minCnt = (n + 1) / 2;


        if(nc0 + nc1 >= minCnt){
            return true;
        }

        if(b[i] == 1){
            return false;
        }

        if(nc0 + m < minCnt){
            return false;
        }

        ll req = minCnt - nc0 - nc1;
        ll r = m - 1 - nc1;
        ll l = r - req + 1;

        ll cost = x * (r - l + 1) - sum1(l, r);

        if(cost > k){
            return false;
        }

        return true;
    };

    auto median = [&](ll i){
        ll l = 0, r = INF;
        while(l < r){
            ll x = (l + r + 1) / 2;
            if(check(x, i)){
                l = x;
            }
            else{
                r = x - 1;
            }
        }
        return l;
    };

    ll res = 0;
    for(ll i = 0; i < n; ++i){
        if(b[i] == 0){
            res = max(res, a[i] + median(i));
        }
        else{
            res = max(res, a[i] + median(i) + k);
        }
    }
    cout << res << '\n';
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
 
