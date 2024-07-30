#include <bits/stdc++.h>
 
using namespace std;

int minCost;
int cnt3;
int n, m;
int INF;
vector<vector<int>> maze;
vector<vector<bool>> vis;
int tr, tc, sr, sc;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool check(int x, int y){
    return ((x >= 0) && (y >= 0) && (x < n) && (y < m) && (maze[x][y] != 1) && !vis[x][y]);
}
void dfs(int r, int c, int numMoves, int num2, int num3){
    if((r == tr) && (c == tc)){
        if(num3 < cnt3){
            minCost = numMoves;
            cnt3 = num3;
        }
        else if((num3 == cnt3) && (minCost > numMoves)){
            minCost = numMoves;
        }
        return;
    }

    vis[r][c] = true;

    for(auto dd: d){
        int dx, dy;
        tie(dx, dy) = dd;
        int x = r + dx, y = c + dy;
        if(!check(x, y)){
            continue;
        }
        if((numMoves + 1 > minCost) && (num3 >= cnt3)){
            continue;
        }
        if((maze[x][y] == 2) && (num2 == 2)){
            continue;
        }
        if(((maze[x][y] == 3) + num3) > cnt3){
            continue;
        }
        dfs(x, y, numMoves + 1, num2 + (maze[x][y] == 2), num3+ (maze[x][y] == 3));
    }

    vis[r][c] = false;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> n >> m;
    maze = vector<vector<int>>(n, vector<int>(m));
    vis = vector<vector<bool>>(n, vector<bool>(m));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> maze[i][j];
        }
    }
    cin >> sr >> sc;
    cin >> tr >> tc;

    minCost = n * m + 1;
    cnt3 = 10000;
    INF = n * m + 1;

    dfs(sr, sc, 0, (maze[sr][sc] == 2), (maze[sr][sc] == 3));


    if(minCost == INF){
        cout << "STUCK";
    }
    else{
        cout << minCost;
    }
    return 0;
}
 
