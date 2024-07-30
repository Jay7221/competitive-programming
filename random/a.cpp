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
vector<int> values;
vector<int> freq, tot;
multiset<int> m;
int n;
int k;
pair<int, map<int, int>*> dfs(int u, int p, int &ans){
    if(p != -1){
        if(*(--m.end()) <= k){
            ++ans;
        }
    }
    for(int v: adj[u]){
        if(v != p){
            dfs(v, u, ans);
            int val = value[v];
        }
    }
}

int getMax(int n, int k, vector<vector<int>> &edges){
    adj = vector<vector<int>>(n);
    for(vector<int> &edge: edges){
        int u = edge[0] - 1;
        int v = edge[1] - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int val: values){
        ++tot[val];
    }

    for(int elem: tot){
        m.insert(elem);
    }

    int ans = 0;

    dfs(0, -1, ans);

    return ans;
}
 
void solve() {
    cin >> n >> k;
    values = vector<int>(n);
    freq = vector<int>(n + 1);
    tot = vector<int>(n + 1);
    for(int i = 0; i < n; ++i){
        cin >> values[i];
    }
    vector<vector<int>> edges(n - 1, vector<int>(2));
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < 2; ++j){
            cin >> edges[i][j];
        }
    }
    cout << getMax(n, k, edges) << '\n';
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
 
