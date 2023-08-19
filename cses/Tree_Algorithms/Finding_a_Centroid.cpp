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
 
 
int get_centroid(int node, vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> subtree_size(n);
    function<int(int, int)> get_subtree_size;
    get_subtree_size = [&](int node, int par){
        int &res = subtree_size[node];
        res = 1;
        for(int i : adj[node]){
            if(i == par){
                continue;
            }
            res += get_subtree_size(i, node);
        }
        return res;
    };
 
    get_subtree_size(node, -1);
 
    bool repeat = true;
    while(repeat){
        repeat = false;
        for(int i : adj[node]){
            if(subtree_size[i] * 2 > n){
                subtree_size[node] -= subtree_size[i];
                subtree_size[i] += subtree_size[node];
 
                node = i;
                repeat = true;
 
                break;
            }
        }
    }
    return node;
}
 
void solve() {
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << get_centroid(0, adj) + 1 << '\n';
}
 
