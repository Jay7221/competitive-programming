#include<bits/stdc++.h>
using namespace std;

const int MAX_A = 3e5 + 7;
const int INF = 1e9 + 7;
vector<int> factorize(int n)
{
	vector<int> factors;
	for(int i = 2; i * i <= n; ++i)
	{
		if(n % i)
		{
			continue;
		}
		factors.push_back(i);
		while(n % i == 0)
		{
			n /= i;
		}
	}
	if(n > 1)
	{
		factors.push_back(n);
	}
	return factors;
}
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> nodes(MAX_A);
	vector<vector<int>> factors(n);
	vector<bool> vis(n), visPrime(MAX_A);
	vector<int> backlink(n, -1), dist(n, INF);
	int s, t;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cin >> s >> t;
	--s, --t;
	for(int i = 0; i < n; ++i)
	{
		factors[i] = factorize(a[i]);
		for(int p : factors[i])
		{
			nodes[p].push_back(i);
		}
	}
	queue<int> q;
	q.push(s);
	vis[s] = true;
	dist[s] = 0;
	while(q.size())
	{
		int u = q.front();
		q.pop();
		for(auto p : factors[u])
		{
			if(visPrime[p])
			{
				continue;
			}
			visPrime[p] = true;
			for(auto v : nodes[p])
			{
				if(vis[v])
				{
					continue;
				}
				vis[v] = true;
				dist[v] = dist[u] + 1;
				backlink[v] = u;
				q.push(v);
			}
		}
	}
	if(dist[t] == INF)
	{
		cout << -1 << '\n';
	}
	else
	{
		vector<int> path;
		int cur = t;
		while(cur != -1)
		{
			path.push_back(cur + 1);
			cur = backlink[cur];
		}
		reverse(path.begin(), path.end());
		cout << path.size() << '\n';
		for(int node : path)
		{
			cout << node << ' ';
		}
		cout << '\n';
	}
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