#include <bits/stdc++.h>
 
using namespace std;
const int INF = 1e9 + 7;
 
vector<int> shift_left(vector<int> p){
    int first = p[0];
    p[0] = p[1];
    p[1] = p[2];
    p[2] = first;
    return p;
}
 
vector<int> shift_right(vector<int> p){
    int last = p[2];
    p[2] = p[1];
    p[1] = p[0];
    p[0] = last;
    return p;
}

vector<int> reverse(vector<int> p){
    reverse(p.begin(), p.end());
    return p;
}

vector<int> apply(vector<int> p1, vector<int> p2){
    for(int i = 0; i < 3; ++i){
        p1[i] += p2[i];
    }
    int mn = min({p1[0], p1[1], p1[2]});
    for(int i = 0; i < 3; ++i){
        p1[i] -= mn;
    }
    return p1;
}

bool is_valid(vector<int> xx){
    int mx = max({xx[0], xx[1], xx[2]});
    return (mx < 20);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    vector<vector<int>> p(n, vector<int>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> p[i][j];
        }
    }

    vector<int> s(m);
    map<vector<int>, int> dp;
    dp[s] = 0;

    for(int i = 0; i < n; ++i){
        map<vector<int>, int> new_dp;
        map<vector<int>, bool> vis;
        for(auto [x, v]: dp){
            vector<int> xx;

            xx = apply(x, p[i]);
            if(new_dp.find(xx) == new_dp.end()){
                new_dp[xx] = INF;
            }
            new_dp[xx] = min(dp[x], new_dp[xx]);

            xx = apply(x, shift_left(p[i]));
            if(!vis[xx]){
                vis[xx] = true;
                new_dp[xx] = INF;
            }
            new_dp[xx] = min(dp[x] + X, new_dp[xx]);

            xx = apply(x, shift_right(p[i]));
            if(!vis[xx]){
                vis[xx] = true;
                new_dp[xx] = INF;
            }
            new_dp[xx] = min(dp[x] + X, new_dp[xx]);

            xx = apply(x, reverse(p[i]));
            if(!vis[xx]){
                vis[xx] = true;
                new_dp[xx] = INF;
            }
            new_dp[xx] = min(dp[x] + Y, new_dp[xx]);
        }
        dp = new_dp;
    }

    if(dp.find(s) != dp.end()){
        cout << dp[s] << '\n';
    }
    else{
        cout << -1 << '\n';
    }
    
    return 0;
}
 
