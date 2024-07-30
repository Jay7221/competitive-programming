#include <bits/stdc++.h>
 
using namespace std;
 
 
#define ll long long
 
class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        return (x == parent[x]) ? x : parent[x] = find(parent[x]);
    }

    int getSize(int x){
        x = find(x);
        return size[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false; // Already in the same set
        }

        // Union by size: attach smaller tree under larger tree
        if (size[rootX] < size[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        size[rootX] += size[rootY];

        return true;
    }

};

ll minimumSum(int n, vector<int> weight, vector<vector<int>> edges){
    ll ans = 0;
    vector<vector<int>> wedges;
    for(vector<int> &edge: edges){
        int u = edge[0];
        int v = edge[1];
        wedges.push_back({min(weight[u], weight[v]), u, v});
    }
    DSU dsu(n);
    sort(wedges.begin(), wedges.end());
    for(int i = n - 2; i >= 0; --i){
        int w = wedges[i][0];
        int u = wedges[i][1];
        int v = wedges[i][2];

        ans += w * 1ll * dsu.getSize(u) * 1ll * dsu.getSize(v);
        dsu.unite(u, v);
    }
    return ans;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> weight(n);
    for(int i = 0; i < n; ++i){
        cin >> weight[i];
    }
    vector<vector<int>> edges(n - 1, vector<int>(2));
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < 2; ++j){
            cin >> edges[i][j];
        }
    }

    cout << minimumSum(n, weight, edges);
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
 
