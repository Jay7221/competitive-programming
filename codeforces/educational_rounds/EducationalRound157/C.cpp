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
 
const ll MAX = 1000;
void solve() {
    ll n;
    cin >> n;
    vector<string> arr(n);
    for(ll i = 0; i < n; ++i){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), [](string s1, string s2){
        return (s1.size() < s2.size());
    });
    vector<vector<ll>> freq(10, vector<ll>(MAX));

    ll ans = 0;
    for(string s : arr){
        ll n = s.size();
        for(ll m = 1; m <= n; ++m){
            if((n + m) & 1){
                continue;
            }
            ll mid = (n + m) / 2;
            ll req = 0;
            for(ll i = 0; i < mid; ++i){
                req += (s[i] - '0');
            }
            for(ll i = mid; i < n; ++i){
                req -= (s[i] - '0');
            }
            if(req >= 0){
                ans += freq[m][req];
            }
        }
        reverse(s.begin(), s.end());
        for(ll m = 1; m <= n; ++m){
            if((n + m) & 1){
                continue;
            }
            ll mid = (n + m) / 2;
            ll req = 0;
            for(ll i = 0; i < mid; ++i){
                req += (s[i] - '0');
            }
            for(ll i = mid; i < n; ++i){
                req -= (s[i] - '0');
            }
            if(req >= 0){
                ans += freq[m][req];
            }
        }
        ++ans;
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += (s[i] - '0');
        }
        ++freq[n][sum];
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
