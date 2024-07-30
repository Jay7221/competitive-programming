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
 
int max_xor(vector<int> arr, int n)
{
    int maxx = 0, mask = 0;
 
    set<int> se;
 
    for (int i = 30; i >= 0; i--) {
 
        // set the i'th bit in mask
        // like 100000, 110000, 111000..
        mask |= (1 << i);
 
        for (int i = 0; i < n; ++i) {
 
            // Just keep the prefix till
            // i'th bit neglecting all
            // the bit's after i'th bit
            se.insert(arr[i] & mask);
        }
 
        int newMaxx = maxx | (1 << i);
 
        for (int prefix : se) {
 
            // find two pair in set
            // such that a^b = newMaxx
            // which is the highest
            // possible bit can be obtained
            if (se.count(newMaxx ^ prefix)) {
                maxx = newMaxx;
                break;
            }
        }
 
        // clear the set for next
        // iteration
        se.clear();
    }
 
    return maxx;
}
 
void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < n - 1; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> pre(n);
    function<void(int, int)> dfs = [&](int u, int p){
        for(auto [v, w]: adj[u]){
            if(v != p){
                pre[v] = pre[u] ^ w;
                dfs(v, u);
            }
        }
    };

    dfs(0, -1);

    cout << max_xor(pre, n) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
