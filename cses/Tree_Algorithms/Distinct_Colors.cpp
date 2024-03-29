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
 
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
 
#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
 
// -------------------------<RNG>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
 
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> c(n);
    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<set<int>> colors(n);
    vector<int> noColor(n);

    function<set<int>&(set<int>&, set<int>&)> merge;
    function<void(int, int)> dfs;

    merge = [&](set<int> &a, set<int> &b) -> set<int>& {
        if(a.size() < b.size()){
            swap(a, b);
        }
        for(int elem : b){
            a.insert(elem);
        }
        return a;
    };
    dfs = [&](int node, int p){
        colors[node].insert(c[node]);
        for(int v : adj[node]){
            if(v == p){
                continue;
            }
            dfs(v, node);
            colors[node] = merge(colors[node], colors[v]);
        }
        noColor[node] = colors[node].size();
    };
    dfs(0, -1);
    for(int i = 0; i < n; ++i){
        cout << noColor[i] << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
