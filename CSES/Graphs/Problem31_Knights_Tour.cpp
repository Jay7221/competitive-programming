#include<bits/stdc++.h>
using namespace std;
const int N = 8;
const int MAX = N * N;
vector<pair<int, int>> graph[N][N];
int path[N][N];
bool vis[N][N];
int check(int x, int y)
{
	int ans = 0;
	for(auto [xx, yy] : graph[x][y])
	{
		ans += (!vis[xx][yy]);
	}
	return ans;
}
bool dfs(int x, int y, int cur = 1)
{
	vis[x][y] = true;
	path[x][y] = cur;
	if(cur == MAX)
	{
		return true ;
	}
	vector<tuple<int, int, int>> vv;
	for(auto [u, v] : graph[x][y])
	{
		if(!vis[u][v])
		{
			vv.push_back({check(u, v), u, v});
		}
	}
	sort(vv.begin(), vv.end());
	for(auto [x, u, v] : vv)
	{
		if(dfs(u, v, cur + 1))
		{
			return true;
		}
	}
	vis[x][y] = false;
	return false;
}
void pre()
{
	vector<pair<int, int>> d = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			for(auto [dx, dy] : d)
			{
				int x = i + dx, y = j + dy;
				if((x >= 0) && (y >= 0) && (x < N) && (y < N))
				{
					graph[i][j].push_back({x, y});
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pre();
	int x, y;
	cin >> x >> y;
	--x, --y;
	dfs(y, x, 1);
	for(int i = 0; i < 8; ++i)
	{
		for(int j = 0; j < 8; ++j)
		{
			// cerr << i << ' ' << j << " : ";
			// for(auto [u, v] : graph[i][j])
			// {
			// 	cerr << u << ' ' << v << ", ";
			// }
			// cerr << '\n';
			cout << path[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
