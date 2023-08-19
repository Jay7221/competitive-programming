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
 
const int INF = 1e9 + 7;
 
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    // pre[i][j] = len of longes subseg of 0s that can be obtained in s[:i], which ends at i and costs exactly j operations
    vector<vector<ll>> pre(n + 1, vector<ll>(n + 1));
    vector<vector<ll>> suf(n + 1, vector<ll>(n + 1));
    for(ll l = 0; l < n; ++l){
        int cnt1 = 0;
        for(ll r = l + 1; r <= n; ++r){
            cnt1 += (s[r - 1] == '1');
            pre[r][cnt1] = max(pre[r][cnt1], r - l);
            suf[l][cnt1] = max(suf[l][cnt1], r - l);
        }
    }
    for(ll r = 0; r <= n; ++r){
        for(ll cnt = 0; cnt <= n; ++cnt){
            if(r){
                pre[r][cnt] = max(pre[r][cnt], pre[r - 1][cnt]);
            }
            if(cnt){
                pre[r][cnt] = max(pre[r][cnt], pre[r][cnt - 1]);
            }
        }
    }
    for(ll l = n; l >= 0; --l){
        for(ll cnt = 0; cnt <= n; ++cnt){
            if(l + 1 <= n){
                suf[l][cnt] = max(suf[l][cnt], suf[l + 1][cnt]);
            }
            if(cnt){
                suf[l][cnt] = max(suf[l][cnt], suf[l][cnt - 1]);
            }
        }
    }

    vector<ll> ans(n + 1, -INF);
    vector<ll> dp(n + 1, -INF);
    for(ll l = 0; l < n; ++l){
        ll cnt0 = 0;
        for(ll r = l; r <= n; ++r){
            if(r > l){
                cnt0 += (s[r - 1] == '0');
            }
            if(cnt0 > k){
                break;
            }
            dp[r - l] = max(dp[r - l], pre[l][k - cnt0]);
            dp[r - l] = max(dp[r - l], suf[r][k - cnt0]);
        }
    }
    for(int i = 0; i <= n; ++i){
        for(int a = 1; a <= n; ++a){
            ans[a] = max(ans[a], i + dp[i] * a);
        }
    }
    for(int i = 1; i <= n; ++i){
        cout  << ans[i] << ' ';
    }
    cout << '\n';
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
 
