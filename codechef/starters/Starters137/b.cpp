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
 
 
bool solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n), h(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> h[i];
    }

    vector<ll> preh = h;
    for(int i = 1; i < n; ++i){
        preh[i] += preh[i - 1];
    }

    vector<ll> req(n);
    for(int i = 0; i < n; ++i){
        req[i] = max(0ll, preh[i] - a[i]);
    }
    vector<ll> suf = req;
    for(int i = n - 2; i >= 0; --i){
        suf[i] = max(suf[i], suf[i + 1]);
    }

    int prev = 0;
    ll cur = 0;
    for(int i = 0; i < n; ++i){
        while(a[i] - a[prev] > 2 * k){
            if(req[prev] > 0){
                return false;
            }
            cur -= h[prev];
            ++prev;
        }
        assert((a[i] - a[prev]) <= 2 * k);
        cur += h[i];
        if(suf[i] <= cur){
            return true;
        }
    }
    return false;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        if(solve()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}
 
