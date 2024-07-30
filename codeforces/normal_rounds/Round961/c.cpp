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
 
ll check_upper(ll x, ll p, ll y){
    ll res = 1;
    while(p){
        if(p & 1){
            res *= x;
            if(res >= y){
                return true;
            }
        }
        if(x >= y){
            return true;
        }
        x *= x;
        p >>= 1;
    }
    return res >= y;
}

// upper bound
ll log_upper(ll x, ll y){
    ll l = 1, r = 60;
    while(l < r){
        ll mid = (l + r) / 2;
        if(check_upper(x, mid, y)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}


ll check_lower(ll x, ll p, ll y){
    ll res = 1;
    while(p){
        if(p & 1){
            res *= x;
            if(res > y){
                return false;
            }
        }
        if(x > y){
            return false;
        }
        x *= x;
        p >>= 1;
    }
    return res <= y;
}

// lower bound
ll log_lower(ll x, ll y){
    ll l = 0, r = 60;
    while(l < r){
        ll mid = (l + r + 1) / 2;
        if(check_lower(x, mid, y)){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    return l;
}
 
ll solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
    }

    ll premax = a[0];
    ll k = 0;
    ll numOperations = 0;
    for(ll i = 1; i < n; ++i){
        if((a[i] == 1) && (premax > 1)){
            return -1;
        }
        if(premax == 1){
            premax = a[i];
            k = 0;
            continue;
        }
        if(a[i] >= premax){
            k -= log_lower(2, log_lower(premax, a[i]));
            k = max(k, 0ll);
        }
        else{
            k += log_upper(2, log_upper(a[i], premax));
            k = max(k, 0ll);
        }
        numOperations += k;
        premax = a[i];
    }

    return numOperations;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        cout << solve() << '\n';
    }
    
    return 0;
}
 
