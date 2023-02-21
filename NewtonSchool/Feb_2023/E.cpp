#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> graph(n);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<bool> isInCapital(n);
	vector<int> in(n), out(n);
	for(int i = 0; i < n; ++i)
	{
		out[i] = graph[i].size();
	}
	priority_queue<pair<int, int>> q;
	q.push(make_pair(-out[0], 0));
	int ans = 0;
	int cur = 0;
	while(q.size())
	{
		int u, du;
		tie(du, u) = q.top();
		q.pop();
		if(isInCapital[u])
		{
			continue;
		}
		++ans;
		cur += -du;
		isInCapital[u] = true;
		for(int v : graph[u])
		{
			if(!isInCapital[v])
			{
				++in[v];
				--out[v];
				q.push(make_pair(in[v] - out[v], v));
			}
		}
		if(cur <= k)
		{
			break;
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
	t = 1;
	while(t--)
	{
		solve();
	}

	return 0;
}