#include<bits/stdc++.h>
using namespace std;

const int MAX_A = 3e5 + 7;
const int INF = 1e9 + 7;
vector<int> primes;
void pre()
{
	vector<bool> isPrime(MAX_A, true);
	for(int i = 2; i < MAX_A; ++i)
	{
		if(isPrime[i])
		{
			primes.push_back(i);
			for(int j = 2; i * j < MAX_A; ++j)
			{
				isPrime[i * j] = false;
			}
		}
	}
}
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
vector<int> djkstra(int s, int t, vector<vector<pair<int, int>>> &graph)
{
	vector<bool> vis(MAX_A);
	vector<int> dist(MAX_A, INF);
	vector<int> backlink(MAX_A, -1);
	dist[s] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({-dist[s], s});
	while(pq.size())
	{
		int du, u;
		tie(du, u) = pq.top();
		pq.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u] = true;
		for(auto [v, w] : graph[u])
		{
			if(dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				pq.push({-dist[v], v});
				backlink[v] = u;
			}
		}
	}
	if(dist[t] == INF)
	{
		return {-1};
	}
	vector<int> path;
	int cur = t;
	while(cur != -1)
	{
		path.push_back(cur);
		if(backlink[cur] == -1)
		{
			cur = backlink[cur];
		}
		else
		{
			cur = backlink[backlink[cur]];
		}
	}
	reverse(path.begin(), path.end());
	return path;
}
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> indexOf(MAX_A);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		indexOf[a[i]] = i + 1;
	}
	vector<vector<pair<int, int>>> graph(MAX_A);
	for(int i = 0; i < n; ++i)
	{
		for(int p : factorize(a[i]))
		{
			graph[a[i]].push_back({p, 1});
			graph[p].push_back({a[i], 0});
		}
	}
	int s, t;
	cin >> s >> t;
	--s, --t;
	indexOf[a[s]] = s + 1;
	indexOf[a[t]] = t + 1;
	if(s == t)
	{
		cout << 1 << '\n' << s+1 << '\n';
		return;
	}
	if(a[s] == a[t])
	{
		if(a[s] == 1)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << 2 << '\n' << s+1 << ' ' << t+1 << '\n';
		}
		return;
	}
	s = a[s], t = a[t];
	vector<int> path = djkstra(s, t, graph);
	if(path.front() == -1)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << path.size() << '\n';
		for(int elem : path)
		{
			cout << indexOf[elem] << ' ';
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	pre();
	int t;
	t = 1;
	while(t--)
	{
		solve();
	}

	return 0;
}