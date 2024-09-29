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
vector<int> par;

unordered_map<int, bool>* merge(unordered_map<int, bool> *a, unordered_map<int, bool>* b){
    if(a -> size() < b -> size()){
        swap(a, b);
    }
    for(auto [elem, _]: *b){
        (*a)[elem] = true;
    }
    return a;
}

unordered_map<int, bool>* dfs(int u){
    unordered_map<int, bool> *nums = new unordered_map<int, bool>();
    for(int v: adj[u]){
        nums = merge(nums, dfs(v));
    }
    for(int d: divisors[u + 1]){
        if((*nums)[d]){
            dp[u] = d;
        }
        else{
            (*nums)[d] = true;
        }
    }
    return nums;
}

void dfs1(int u, int p){
    par[u] = p;
    for(int v: adj[u]){
        if(v != p){
            dfs1(v, u);
        }
    }
}
 
void solve() {
    int n, r;
    cin >> n >> r;
    --r;

    adj = vector<vector<int>>(n);
    dp = vector<int>(n, -1);
    par = vector<int>(n, -1);

    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(r, -1);

    for(int i = 0; i < n; ++i){
        while((par[i] != -1) && (par[i] < i)){
            par[i] = par[par[i]];
        }
    }

    adj = vector<vector<int>>(n);
    for(int i = 0; i < n; ++i){
        if(par[i] != -1){
            adj[par[i]].push_back(i);
        }
    }

    for(int i = 0; i < n; ++i){
        if(par[i] == -1){
            dfs(i);
        }
    }

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
 
