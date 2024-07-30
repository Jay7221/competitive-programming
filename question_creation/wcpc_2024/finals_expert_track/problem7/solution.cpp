#include<bits/stdc++.h>
using namespace std;
vector<int> tour;
vector<int> vis;
vector<vector<int>> adj;
bool dfs(int u){
    // processing
    vis[u] = 1;
    for(int v: adj[u]){
        if(vis[v] == 0){
            if(!dfs(v)){
                return false;
            }
        }
        else if(vis[v] == 1){
            return false;
        }
    }
    // done
    vis[u] = 2;
    tour.push_back(u);
    return true;
}

const int MAX_N = 2e5 + 7;
vector<long long> factorial(MAX_N);
const long long MOD = 1e9 + 7;
long long add(long long a, long long b){
    return ((a + 0ll + b) % MOD);
}
long long sub(long long a, long long b){
    return ((a - b + MOD) % MOD);
}
long long mult(long long a, long long b){
    return (a * b) % MOD;
}
long long power(long long a, long long p){
    long long res = 1;
    while(p){
        if(p & 1){
            res = mult(res, a);
        }
        a = mult(a, a);
        p >>= 1;
    }
    return res;
}
long long divide(long long a, long long b){
    return mult(a, power(b, MOD - 2));
}
void pre(){
    factorial[0] = 1;
    for(int i = 1; i < MAX_N; ++i){
        factorial[i] = mult(i, factorial[i - 1]);
    }
}



void solve(){
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    vis = vector<int>(n + 1);
    vector<int> out(n + 1);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        ++out[u];
    }
    for(int i = 1; i <= n; ++i){
        if(out[i] == 0){
            adj[0].push_back(i);
        }
    }

    tour.clear();
    if(dfs(0) && (*min_element(vis.begin(), vis.end()) != 0)){
        vector<int> dp(n + 1, 1), sz(n + 1, 1);
        for(int u: tour){
            for(int v: adj[u]){
                sz[u] += sz[v];
                dp[u] = mult(dp[u], dp[v]);
                dp[u] = divide(dp[u], factorial[sz[v]]);
            }
            dp[u] = mult(dp[u], factorial[sz[u] - 1]);
        }
        cout << dp[0];
    }
    else{
        cout << 0;
    }
}
int main(){
    pre();
    solve();
    return 0;
}
