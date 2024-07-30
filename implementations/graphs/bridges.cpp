#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> discovery, low, parent, subtree;
vector<pair<int, int>> bridges;
void initialize(int n){
    graph = vector<vector<int>>(n);

    discovery = vector<int>(n, -1);
    low = vector<int>(n);
    parent = vector<int>(n);
    subtree = vector<int>(n, 1);
}

void dfs(int u, int &time){
    discovery[u] = low[u] = ++time;
    for(int v: graph[u]){
        if(discovery[v] == -1){
            parent[v] = u;
            dfs(v, time);
            subtree[u] += subtree[v];

            low[u] = min(low[u], low[v]);

            if(low[v] > discovery[u]){
                bridges.push_back({u, v});
            }
        } else if(v != parent[u]){
            low[u] = min(low[u], discovery[v]);
        }
    }
}
 

int main(){
    return 0;
}
