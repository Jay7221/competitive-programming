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



 // Utility function to perform Depth First Search (DFS) and find the diameter path
void dfs(int node, vector<vector<int>>& tree, vector<bool>& visited, int depth, vector<int>& distances, int& farthestNode, vector<int>& diameterPath, vector<int>& currentPath) {
    visited[node] = true;
    distances[node] = depth;
    currentPath.push_back(node);
    
    if (depth > distances[farthestNode]) {
        farthestNode = node;
        diameterPath = currentPath;
    }
    
    for (int child : tree[node]) {
        if (!visited[child]) {
            dfs(child, tree, visited, depth + 1, distances, farthestNode, diameterPath, currentPath);
        }
    }
    
    currentPath.pop_back(); // Backtrack
}

// Function to find the diameter of the tree and return the nodes on the diameter
vector<int> treeDiameterNodes(vector<vector<int>>& tree) {
    int n = tree.size();
    if (n == 0) return {}; // Empty tree
    
    vector<bool> visited(n, false);
    vector<int> distances(n, 0);
    vector<int> diameterPath;
    vector<int> currentPath;
    
    int farthestNode = 0;
    // Perform DFS from any arbitrary node to find the farthest node and diameter path
    dfs(0, tree, visited, 0, distances, farthestNode, diameterPath, currentPath);
    
    // Reset visited array and distances
    fill(visited.begin(), visited.end(), false);
    fill(distances.begin(), distances.end(), 0);
    currentPath.clear();
    
    // Perform DFS from the farthest node to find the second farthest node
    dfs(farthestNode, tree, visited, 0, distances, farthestNode, diameterPath, currentPath);
    
    // Return the nodes on the diameter path
    return diameterPath;
}
 
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
    vector<int> path = treeDiameterNodes(adj);
    deque<int> dq;
    for(int u: path){
        dq.push_back(u);
    }
    vector<int> color(n);
    int red = 0, blue = 0;
    while((int)dq.size() > 1){
        color[dq.front()] = 1;
        color[dq.back()] = 2;
        dq.pop_back();
        dq.pop_front();
    }
    if(!dq.empty()){
        color[dq.back()] = 1;
        ++red;
        dq.pop_back();
    }

    for(int i = 0; i < n; ++i){
        if(color[i] == 0){
            if(red > blue){
                color[i] = 2;
                ++blue;
            }
            else{
                color[i] = 1;
                ++red;
            }
        }
    }

    for(int i = 0; i < n; ++i){
        if(color[i] == 1){
            cout << "R";
        }
        else{
            cout << "B";
        }
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
 
