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
 
bool check(int n, int k, vector<int> &a, vector<int> &b){
    for(int i = 0; i < n; ++i){
        k -= a[i] + b[i];
    }
    return (k <= 0);
}

#define pii pair<int, int>
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i];
    }

    vector<vector<int>> cost(n);
    for(int i = 0; i < n; ++i){
        int x = min(a[i], b[i]);
        int y = max(a[i], b[i]);
        int curCost = 0;
        while(x > 0){
            curCost += x;
            --y;
            if(x > y){
                swap(x, y);
            }
            cost[i].push_back(curCost);
        }
    }

    vector<int> dp(k + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 0; i < n; ++i){
        for(int w = k; w >= 0; --w){
            for(int j = 0; j < min(w + 1, (int)cost[i].size()); ++j){
                int p = (j == (int)cost[i].size() - 1) ? j + 2 : j + 1;
                p = min(p, w);
                if(dp[w - p] != INT_MAX){
                    dp[w] = min(dp[w - p] + cost[i][j], dp[w]);
                }
            }
        }
    }


    dp[k] = (dp[k] == INT_MAX) ? -1 : dp[k];
    cout << dp[k] << '\n';
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
 
