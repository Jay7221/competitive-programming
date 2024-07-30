#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> ind(10);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        ind[a[i]].push_back(i);
    }
    vector<vector<int>> adj(n);
    for(int i = 1; i < n; ++i){
        adj[i].push_back(i - 1);
    }
    for(int i = 0; i < n - 1; ++i){
        adj[i].push_back(i + 1);
    }
    for(auto v: ind){
        for(int i = 1; i < (int)v.size(); ++i){
            adj[v[0]].push_back(v[i]);
        }
    }
    vector<int> d(n, n + 1);
    d[0] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({-d[0], 0});
    while(!pq.empty()){
        int dd, u;
        tie(dd, u) = pq.top();
        pq.pop();
        dd = -dd;
        if(dd > d[u]){
            continue;
        }
        for(int v : adj[u]){
            if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                pq.push({-d[v], v});
            }
        }
    }
    cout << d[n - 1] << '\n';
}
