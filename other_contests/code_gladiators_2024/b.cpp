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
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    string color;
    cin >> color;

    if((count(color.begin(), color.end(), 'R') & 1) == 0){
        for(int i = 0; i < n; ++i){
            cout << n << '\n';
        }
        return;
    }

    vector<int> subtree(n, 1);
    vector<int> red(n, 0);
    vector<int> back(n, -1);
    function<void(int, int)> dfs = [&](int u, int p){
        for(int v: adj[u]){
            if(v != p){
                dfs(v, u);
                subtree[u] += subtree[v];
                if(red[u] < red[v]){
                    red[u] = red[v];
                    back[u] = v;
                }
                if(color[v] == 'R'){
                    if(red[u] < n - subtree[v]){
                        red[u] = n - subtree[v];
                        back[u] = v;
                    }
                }
            }
        }
    };

    function<void(int, int)> dfs2 = [&](int u, int p){
        for(int v: adj[u]){
            if(v != p){
                if(color[u] == 'R'){
                    red[v] = max(red[v], subtree[v]);
                }
                if(back[u] != v){
                    red[v] = max(red[v], red[u]);
                }
                dfs2(v, u);
            }
        }
    };



    dfs(0, -1);
    dfs2(0, -1);

    int mn = *min_element(red.begin(), red.end());
    int mx = *max_element(red.begin(), red.end());

    vector<int> ans = red;
    red.assign(n, 0);
    subtree.assign(n, 1);

    int cnt = 0;
    for(int i = 0; i < n; ++i){
        cnt += (ans[i] == mn) && (color[i] == 'R');
    }

    if(cnt > 1){
        for(int i = 0; i < n; ++i){
            ans[i] = mx;
        }
    }

    for(int i = 0; i < n; ++i){
        if((color[i] == 'R') && (ans[i] == mn)){
            dfs(i, -1);
            dfs2(i, -1);
            break;
        }
    }
    for(int i = 0; i < n; ++i){
        ans[i] = max(ans[i], red[i]);
    }

    for(int i = 0; i < n; ++i){
        cout << ans[i] << '\n';
    }

}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
