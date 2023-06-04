#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n), c(m), freq(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		--a[i];
		++freq[a[i]];
	}
	for(int i = 0; i < m; ++i)
	{
		cin >> c[i];
	}
	int ans = 0;
	priority_queue<pair<int, int>> tables;
	priority_queue<int> people;
	for(int i = 0; i < n; ++i)
	{
		if(freq[i])
		{
			people.push({freq[i]});
		}
	}
	for(int i = 0; i < m; ++i)
	{
		tables.push({1, c[i]});
	}
	while(people.size())
	{
		int u = people.top();
		people.pop();
		int x = tables.top().second;
		int flag = tables.top().first;
		tables.pop();

		int tmp = min(x, u);
		x -= tmp;
		u -= tmp;
		if(flag)
		{
			ans += tmp;
		}
		if(x > 0)
		{
			tables.push({0, x});
		}
		if(u > 0)
		{
			people.push(u);
		}
	}
	cout << ans << '\n';
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