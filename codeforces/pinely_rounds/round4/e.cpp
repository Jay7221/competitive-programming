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
 
vector<int> color;
vector<bool> vis;
vector<vector<int>> adj;
bool isBipartite;

void dfs(int u){
    vis[u] = true;
    for(int v: adj[u]){
        if(vis[v]){
            if(color[u] == color[v]){
                isBipartite = false;
            }
        }
        else{
            color[v] = color[u] ^ 1;
            dfs(v);
        }
    }
}
 
void solve() {
    int n, m;;
    cin >> n >> m;

    color = vector<int>(n);
    vis = vector<bool>(n);
    adj = vector<vector<int>>(n);
    isBipartite = true;

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);

    vector<int> a, b;
    for(int i = 0; i < n; ++i){
        if(color[i] == 0){
            a.push_back(i + 1);
        }
        else{
            b.push_back(i + 1);
        }
    }

    if(isBipartite){
        cout << "Bob" << endl;

        for(int i = 0; i < n; ++i){
            int col1, col2;
            cin >> col1 >> col2;

            int ind, col;

            if(!a.empty() && ((col1 == 1) || (col2 == 1))){
                ind = a.back();
                a.pop_back();
                col = 1;
            }
            else if(!b.empty() && ((col1 == 2) || (col2 == 2))){
                ind = b.back();
                b.pop_back();
                col = 2;
            }
            else{
                if(!a.empty()){
                    ind = a.back();
                    a.pop_back();
                }
                else{
                    ind = b.back();
                    b.pop_back();
                }
                col = 3;
            }

            cout << ind << ' ' << col << endl;
        }
    }
    else{
        cout << "Alice" << endl;
        for(int i = 0; i < n; ++i){
            cout << "1 2" << endl;
            int ind, col;
            cin >> ind >> col;
        }
    }
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
 
