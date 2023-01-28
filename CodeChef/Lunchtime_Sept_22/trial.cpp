#include <bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
#define debug2(a) for(auto c : a){cerr << c.first << ' ' << c.second << '\n';} cerr << '\n';
const int INF = 1e9 + 7;
int main() {
    // your code goes here
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v(n), dp(n, INF);
    vector<int> cost(10, INF);
    vector<bool> vis(10);
    for(int i = 0; i < n; ++i)
        v[i] = s[i] - '0';
    dp[0] = 0;
    cost[v[0]] = 1;
    for(int k = 0; k < 10; ++k){
        for(int i = 0; i < n; ++i)
            cost[v[i]] = min(cost[v[i]], dp[i] + 1);
        int cur = -1;
        for(int j = 0; j < 10; ++j){
            if(vis[j])
                continue ;
            if(cur == -1)
                cur = j;
            if(cost[cur] > cost[j])
                cur = j;
        }
        vis[cur] = true;;
        queue<int> q;
        for(int i = 0; i < n; ++i){
            if(v[i] == cur){
                dp[i] = min(dp[i], cost[cur]);
                q.push(i);
            }
        }
        vector<bool> visited(n);
        while(q.size()){
            int u = q.front();
            q.pop();
            if(visited[u])
                continue;
            visited[u] = true;
            if(u > 0){
                q.push(u - 1);
                dp[u - 1] = min(dp[u - 1], dp[u] + 1);
            }
            if(u < n - 1){
                dp[u + 1] = min(dp[u + 1], dp[u] + 1);
            }
        }
    }
    cout << dp[n - 1];
    return 0;
}
