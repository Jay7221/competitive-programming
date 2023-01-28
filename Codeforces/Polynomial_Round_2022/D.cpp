#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n, m;
	cin >> n >> m;
	// sum[i] = bit sum of the ith number
	vector<int> sum(n);
	int totalSum = 0;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
			sum[i] += a[i][j];
		}
		totalSum += sum[i];
	}
	if(totalSum % n)
	{
		cout << -1 << '\n';
		return;
	}
	int expected = totalSum / n;
	priority_queue<pair<int, int>> smin, smax;
	for(int i = 0; i < n; ++i)
	{
		if(sum[i] < expected)
		{
			smin.push({expected - sum[i], i});
		}
		if(sum[i] > expected)
		{
			smax.push({sum[i] - expected, i});
		}
	}
	vector<tuple<int, int, int>> ans;
	while(smin.size() && smax.size())
	{
		int s1, x, s2, y;
		tie(s2, x) = smax.top();
		smax.pop();
		tie(s1, y) = smin.top();
		smin.pop();
		// cerr << x << ' ' << y << ' ' << sum[x] << ' ' << sum[y] << ' ' << expected << '\n';
		int sz = min(s1, s2);
		for(int i = 0; (i < m) && (sz > 0); ++i)
		{
			if(a[x][i] & (!a[y][i]))
			{
				swap(a[x][i], a[y][i]);
				ans.push_back({x, y, i});
				--sum[x], ++sum[y];
				sz--;
			}
		}
		if(sum[x] > expected)
		{
			smax.push({sum[x] - expected, x});
		}
		if(sum[y] < expected)
		{
			smin.push({expected - sum[y], y});
		}
	}
	cout << ans.size() << '\n';
	for(auto [x, y, z] : ans)
	{
		cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << '\n';
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}