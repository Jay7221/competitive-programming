#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void dfs(int u, int p, const vector<vector<int>>& graph, const string& str, 
        vector<int>& subtree_size, vector<int>& max_red_distance, int n) {
    for (int v : graph[u]) {
        if (v != p) {
            dfs(v, u, graph, str, subtree_size, max_red_distance, n);
            subtree_size[u] += subtree_size[v];
            if (max_red_distance[u] < max_red_distance[v]) {
                max_red_distance[u] = max_red_distance[v];
            }
            if (str[v] == 'R') {
                if (max_red_distance[u] < n - subtree_size[v]) {
                    max_red_distance[u] = n - subtree_size[v];
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> graph(n);
    
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    string str;
    cin >> str;
    
    if (count(str.begin(), str.end(), 'R') % 2 == 0) {
        for (int i = 0; i < n; ++i) {
            cout << n << '\n';
        }
        return 0;
    }
    
    vector<int> subtree_size(n, 1);
    vector<int> max_red_distance(n, 0);
    
    for (int i = 0; i < n; ++i) {
        max_red_distance.assign(n, 0);
        subtree_size.assign(n, 1);
        dfs(i, -1, graph, str, subtree_size, max_red_distance, n);
        cout << max_red_distance[i] << '\n';
    }

    return 0;
}
