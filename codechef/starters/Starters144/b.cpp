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
 
ll numInversions(vector<ll> &arr, ll l, ll r){
    ll res = 0;
    if(l > r){
        return res;
    }

    assert(r <= arr.size());
    ll cnt0 = count(arr.begin() + l, arr.begin() + r, 0);

    for(ll i = l; i < r; ++i){
        if(arr[i] == 1){
            res += cnt0;
        }
        else{
            --cnt0;
        }
    }
    return res;
}
 
ll solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<ll> arr(n + 2);
    for(ll i = 1; i <= n; ++i){
        arr[i] = (s[i - 1] - '0');
    }
    arr[n + 1] = 1;

    vector<ll> pre = arr, suf = arr;

    for(ll i = 0; i < n + 2; ++i){
        suf[i] = 1 - suf[i];
    }

    for(ll i = 1; i < n + 2; ++i){
        pre[i] += pre[i - 1];
    }
    for(ll i = n; i >= 0; --i){
        suf[i] += suf[i + 1];
    }

    ll res = numInversions(arr, 1, n + 1);

    for(ll l = 0, r = 0; (l <= n) && (pre[l] <= k); ++l){
        while(pre[l] + suf[r] > k){
            ++r;
        }
        res = min(res, numInversions(arr, l + 1, r));
    }
    return res;
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
 
