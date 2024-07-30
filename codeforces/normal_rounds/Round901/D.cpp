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
    int n;
    cin >> n;
    vector<int> a(n), freq(n + 1);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int elem : a){
        if(elem <= n){
            ++freq[elem];
        }
    }

    // lead[f] = the smallest element with frequency f
    vector<int> lead(n + 1, n + 1);
    for(int i = 0; i <= n; ++i){
        lead[freq[i]] = min(i, lead[freq[i]]);
    }
    lead[0] = n + 1;

    vector<vector<int>> children(n + 1);
    for(int mex = 0; mex <= n; ++mex){
        for(int i = 0; i < mex; ++i){
            if(lead[freq[i]] == i){
                children[mex].push_back(i);
            }
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    dp[0].assign(n + 1, 0);

    function<int(int, int)> dfs;
    dfs = [&](int mex, int moves){
        if(dp[mex][moves] != -1){
            return dp[mex][moves];
        }

        dp[mex][moves] = n * n;

        for(int v : children[mex]){
            int new_moves = moves - freq[v];
            int cost = mex * (freq[v] - 1) + v;

            dfs(v, new_moves);

            dp[mex][moves] = min(dp[mex][moves], dp[v][new_moves] + cost);
        }

        return dp[mex][moves];
    };
    int mex = 0;
    while(freq[mex] > 0){
        ++mex;
    }
    dfs(mex, n);
    cout << dp[mex][n] << '\n';
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
 
