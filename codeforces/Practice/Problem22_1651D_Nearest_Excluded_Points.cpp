#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
#define pii pair<int, int>
int dist(pair<int, int> x, pair<int, int> y)
{
	return (abs(x.first - y.first) + abs(x.second + y.second));
}
vector<pii> neighbours(pii p)
{
	int x, y;
	tie(x, y) = p;
	vector<pii> ans;
	vector<pii> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	for(auto [dx, dy] : d)
	{
		ans.push_back({x + dx, y + dy});
	}
	return ans;
}
void print(pii p)
{
	cout << p.first << ' ' << p.second << '\n';
}
void solve()
{
	int n;
	cin >> n;
	map<pii, bool> inPoints;
	set<pair<int, pii>> s;
	map<pii, int> dist;
	map<pii, pii> link;
	vector<pii> v;
	for(int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
		dist[{x, y}] = INF;
		for(pii v : neighbours({x, y}))
		{
			if(dist[v] == 0)
			{
				link[v] = v;
			}
			s.insert({dist[v], v});
		}
	}
	while(s.size())
	{
		int d;
		pii u;
		tie(d, u) = *s.begin();
		s.erase(s.begin());
		for(pii v : neighbours(u))
		{
			if(dist[v] > dist[u] + 1)
			{
				s.erase({dist[v], v});
				dist[v] = dist[u] + 1;
				link[v] = link[u];
				s.insert({dist[v], v});
			}
		}
	}
	for(pii u : v)
	{
		print(link[u]);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}