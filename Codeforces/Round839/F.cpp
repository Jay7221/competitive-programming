#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<vector<bool>>> matrices(k + 2);
	vector<vector<int>> operations;
	auto inputMatrix = [&]()
	{
		vector<vector<bool>> a(n, vector<bool>(m));
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				char tmp;
				cin >> tmp;
				a[i][j] = tmp - '0';
			}
		}
		return a;
	};
	auto printMatrix = [&](int ind)
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				cout << matrices[ind][i][j] << ' ';
			}
			cout << '\n';
		}
	};
	auto isHole = [&](int ind, int x, int y)
	{
		vector<pair<int, int>> v = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		bool ans = true;
		for(auto [dx, dy] : v)
		{
			int xx = x + dx, yy = y + dy;
			ans &= (matrices[ind][x][y] ^ matrices[ind][xx][yy]);
		}
		return ans;
	};
	auto getScore = [&](int ind)
	{
		int ans = 0;
		for(int i = 1; i < n - 1; ++i)
		{
			for(int j = 1; j < m - 1; ++j)
			{
				if(isHole(ind, i, j))
				{
					++ans;
				}
			}
		}
		return ans;
	};
	auto cmp = [&](int ind1, int ind2)
	{
		bool ans = true;
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				if(matrices[ind1][i][j] != matrices[ind2][i][j])
				{
					ans = false;
				}
			}
		}
		return ans;
	};
	auto makeSame = [&](int ind1, int ind2)
	{
		while(!cmp(ind1, ind2))
		{
			for(int i = 1; i < n - 1; ++i)
			{
				for(int j = 1; j < m - 1; ++j)
				{
					if((matrices[ind1][i][j] != matrices[ind2][i][j]) && isHole(ind1, i, j))
					{
						matrices[ind1][i][j] = matrices[ind2][i][j];
						operations.push_back({1, i + 1, j + 1});
					}
				}
			}	
		}
	};
	priority_queue<pair<int, int>> pq;
	for(int i = 1; i <= k + 1; ++i)
	{
		matrices[i] = inputMatrix();
		pq.push({getScore(i), i});
	}
	int prev, tmp;
	tie(tmp, prev) = pq.top();
	pq.pop();
	cout << prev << '\n';
	while(pq.size())
	{
		int cur;
		tie(tmp, cur) = pq.top();
		pq.pop();
		makeSame(prev, cur);
		operations.push_back({2, cur});
		prev = cur;
	}
	cout << operations.size() << '\n';
	for(auto v : operations)
	{
		for(auto elem : v)
		{
			cout << elem << ' ';
		}
		cout << '\n';
	}
	return 0;
}