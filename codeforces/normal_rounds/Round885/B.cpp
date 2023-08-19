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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> ind(k), gap(k);
    for(int i = 0; i < k; ++i){
        ind[i].push_back(-1);
    }
    for(int i = 0; i < n; ++i){
        int c;
        cin >> c;
        --c;
        gap[c].push_back(i - ind[c].back() - 1);
        ind[c].push_back(i);
    }
    for(int c = 0; c < k; ++c){
        gap[c].push_back(n - 1 - ind[c].back());
        sort(gap[c].begin(), gap[c].end());
    }
    int ans = n;
    for(int c = 0; c < k; ++c){
        int tmp;
        int mx = gap[c].back();
        gap[c].pop_back();
        tmp = mx / 2;
        if(!gap[c].empty()){
            int mx2 = gap[c].back();
            tmp = max(tmp, mx2);
        }
        ans = min(ans, tmp);
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
 
