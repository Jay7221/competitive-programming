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
 
 
int goodTree(int n, vector<int>& color, vector<vector<int>>& edges) {
    for(int i = 0; i < n; ++i){
        color[i] %= 3;
    }
    vector<vector<int>> graph(n);
    for(auto e : edges){
        int u = e[0], v = e[1];
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> vis(n);
    queue<pair<int, int>> q;
    q.push({0, 3 - color[0]});
    while(!q.empty()){
        int u, req;
        tie(u, req) = q.front();
        q.pop();
        vis[u] = true;
        for(int v : graph[u]){
            if(vis[v]){
                continue;
            }
            if((color[v] == 0) && (req > 0)){
                return 0;
            }
            if(req == 3){
                q.push({v, req - color[v]});
            }
            else if(req > 0){
                if(color[v] == req){
                    q.push({v, 0});
                }
                else{
                    q.push({v, req});
                }
            }
            else{
                if(color[v] == 0){
                    q.push({v, 3});
                }
                else{
                    q.push({v, req});
                }
            }
        }
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        int n;
        cin >> n;
        vector<int> c(n);
        for(int i = 0; i < n; ++i){
            cin >> c[i];
        }
        vector<vector<int>> edges;
        for(int i = 0; i < n - 1; ++i){
            vector<int> e(2);
            cin >> e[0] >> e[1];
            edges.push_back(e);
        }
        cout << goodTree(n, c, edges) << '\n';
    }
    
    return 0;
}
 
