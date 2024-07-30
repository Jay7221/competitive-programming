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
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }



    priority_queue<pair<ll, int>> pq;
    for(int i = 0; i < n; ++i){
        pq.push({-a[i], i});
    }

    vector<pair<int, ll>> v;
    for(int i = 0; i * m < k; ++i){
        ll val;
        int ind;
        tie(val, ind) = pq.top();
        pq.pop();
        v.push_back({ind, -val});
    }

    a.clear();
    sort(v.begin(), v.end());
    for(auto [ind, val]: v){
        a.push_back(val);
    }

    n = a.size();

    __int128 tot = m * accumulate(a.begin(), a.end(), 0ll);
    tot += ((m * m * n * (n - 1)) / 2);

    ll rem = m * n - k;
    __int128 ans = -1;
    for(int i = 0; i < n; ++i){
        ll diff = rem * (a[i] + m * (n - 1));
        if(ans == -1){
            ans = tot - diff;
        }
        ans = min(ans, tot - diff);
    }

    ll fans = ans;
    cout << fans << '\n';

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
 
