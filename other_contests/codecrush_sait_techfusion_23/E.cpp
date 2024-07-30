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
 
 
vector<vector<int>> adj;
vector<int> c;
vector<int> dp;
int k;

void dfs(int u){
    for(int v : adj[u]){
        dfs(v);
        if(c[u] == 0){
            // min
            dp[u] += dp[v];
        }
        else{
            // max
            dp[u] = min(dp[u], dp[v]);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    adj.assign(n, vector<int>());
    c.assign(n, 0);
    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }
    for(int i = 1; i < n; ++i){
        int p;
        cin >> p;
        --p;
        adj[p].push_back(i);
    }
    dp.assign(n, 0);
    k = 0;
    for(int i = 0; i < n; ++i){
        if(adj[i].empty()){
            ++k;
            dp[i] = 1;
        }
        else{
            if(c[i] == 0){
                dp[i] = 0;
            }
            else{
                dp[i] = n;
            }
        }
    }
    dfs(0);
    cout << (k - dp[0] + 1) << '\n';
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
 
