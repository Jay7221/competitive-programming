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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    vector<pair<int, int>> v;
    for(int i = 0; i < n; ++i){
        v.push_back({a[i], b[i]});
    }
    sort(v.begin(), v.end());

    vector<int> dp1(m + 1, *min_element(a.begin(), a.end()));
    vector<int> dp2(m + 1, *max_element(a.begin(), a.end()));
    int prev = INF;
    int i = 1;
    for(auto [a, b]: v){
        if(i > m){
            break;
        }
        int x = max(a, b);
        if(prev < x){
            break;
        }
        dp1[i] = x;
        if(i < n){
            int _, na;
            tie(na, _) = v[i];
            dp1[i] = min(dp1[i], na);
        }
        prev = x;
        ++i;
    }
    reverse(v.begin(), v.end());
    prev = 0;
    i = 1;
    for(auto [a, b]: v){
        if(i > m){
            break;
        }
        int x = min(a, b);
        if(prev > x){
            break;
        }
        dp2[i] = x;
        if(i < n){
            int _, na;
            tie(na, _) = v[i];
            dp2[i] = max(dp2[i], na);
        }
        prev = x;
        ++i;
    }
    cerr << dp1 << '\n';
    cerr << dp2 << '\n';

    for(int i = 1; i <= m; ++i){
        dp1[i] = max(dp1[i], dp1[i - 1]);
        dp2[i] = min(dp2[i], dp2[i - 2]);
    }
    int ans = INF;
    for(int i = 0; i <= m; ++i){
        ans = min(ans, dp1[i] + dp2[m - i]);
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
