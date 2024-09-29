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
 
const int MAX_N = 2e5 + 7;
vector<vector<int>> divisors(MAX_N);
void pre(){
    for(int i = 1; i < MAX_N; ++i){
        for(int j = i; j < MAX_N; j += i){
            divisors[j].push_back(i);
        }
    }
}

vector<int> dp;
vector<vector<int>> adj;
vector<unordered_map<int, int>> nums;

void merge(unordered_map<int, int> &mp1, unordered_map<int, int> &mp2){
    if(mp1.size() < mp2.size()){
        swap(mp1, mp2);
    }
    for(auto [d, minV]: mp2){
        if(mp1.count(d)){
            mp1[d] = min(mp1[d], minV);
        }
        else{
            mp1[d] = minV;
        }
    }
}

void dfs(int u, int p){
    for(int v: adj[u]){
        if(v != p){
            dfs(v, u);
            merge(nums[u], nums[v]);
        }
    }

    for(int d: divisors[u + 1]){
        if(nums[u].count(d) && (nums[u][d] < u + 1)){
            dp[u] = max(dp[u], d);
        }
        else{
            nums[u][d] = u;
        }
    }
}
 
void solve() {
    int n, r;
    cin >> n >> r;
    --r;

    adj = vector<vector<int>>(n);
    dp = vector<int>(n, -1);
    nums = vector<unordered_map<int, int>>(n);

    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(r, -1);

    for(int i = 0; i < n; ++i){
        cout << dp[i] << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    pre();

    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 