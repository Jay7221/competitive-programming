#include<bits/stdc++.h>
using namespace std;
int shortestPath(vector<vector<int>>& grid, int k_max) {
        const int INF = 1e9 + 7;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int> > > dp(n, vector<vector<int> >(m, vector<int>(k_max + 1, INF)));
        // dp[i][j][k] = the minimum number of steps from (1, 1) to (i, j) with k bricks eliminated
        dp[0][0][0] = 0;
        set<tuple<int, int, int, int> > s;
        for(int i = 0; i < n;++i){
            for(int j = 0; j < m; ++j){
                for(int k = 0; k < k_max; ++k){
                    s.insert({dp[i][j][k], i, j, k});
                }
            }
        }
        vector<pair<int, int> > d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        auto check = [&](int i, int j){
            if((i < n) && (j < m) && (i >= 0) && (j >= 0))
                return true;
            return false;
        };
        while(s.size()){
            int i, j, k, val;
            tie(val, i, j, k) = *s.begin();
            s.erase(s.begin());
            ++val;
            for(auto [dx, dy] : d){
                int x = i + dx, y = j + dy;
                if(check(x, y)){
                    if(grid[x][y] + k <= k_max){
                        if(dp[x][y][k + grid[x][y]] > val){
                            s.erase({dp[x][y][k + grid[x][y]], x, y, k + grid[x][y]});
                            dp[x][y][k + grid[x][y]] = val;
                            s.insert({dp[x][y][k + grid[x][y]], x, y, k + grid[x][y]});
                        }
                    }

                }
            }
        }
        int ans = INF;
        for(int k = 0; k <= k_max; ++k){
            ans = min(ans, dp[n - 1][m - 1][k]);
        }
        if(ans == INF)
            ans = -1;
        return ans;
    }

int main(){
    int k = 1;
    vector<vector<int> > grid = {
        {0, 0, 0},
        {1, 1, 0},
        {0, 0, 0},
        {0, 1, 1},
        {0, 0, 0},
    };
    cerr << shortestPath(grid, k);
}