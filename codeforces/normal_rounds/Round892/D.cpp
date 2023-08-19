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
    vector<int> l(n), r(n), a(n), b(n);
    vector<tuple<int, int, int>> v;
    // v[i] = {position, type, index}
    for(int i = 0; i < n; ++i){
        cin >> l[i] >> r[i] >> a[i] >> b[i];
        v.push_back({l[i], 0, i});
        v.push_back({b[i], 1, i});
    }

    vector<vector<int>> graph(n);
    sort(v.begin(), v.end());
    int cur = -1;
    for(auto [pos, type, ind] : v){
        if(type == 0){
            if(cur == -1){
                cur = ind;
            }
            if(b[cur] < b[ind]){
                cur = ind;
            }
        }
        else{
            if(b[ind] < b[cur]){
                graph[ind].push_back(cur);
            }
        }
    }

    vector<int> dp(n);
    for(int i = 0; i < n; ++i){
        dp[i] = b[i];
    }
    vector<bool> vis(n);
    function<void(int)> dfs;
    dfs = [&](int u){
        if(vis[u]){
            return;
        }
        vis[u] = true;
        for(int v : graph[u]){
            dfs(v);
            dp[u] = max(dp[u], dp[v]);
        }
    };
    for(int i = 0; i < n; ++i){
        dfs(i);
    }
    map<int, int> mp;
    for(int i = 0; i < n; ++i){
        mp[l[i]] = dp[i];
    }
    vector<int> vv = l;
    sort(vv.begin(), vv.end());
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        if(vv.front() <= x){
            int ind = upper_bound(vv.begin(), vv.end(), x) - vv.begin();
            --ind;
            x = max(x, mp[vv[ind]]);
        }
        cout << x << ' ';
    }
    cout << '\n';
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
 
