#include<bits/stdc++.h>
using namespace std;
#define ll long long
void brute(string &s)
{
	int n = s.size();
	for(int cnt = 0; cnt < n; ++cnt)
	{
		for(int i = 1; i < n; ++i)
		{
			if(s[i - 1] == s[i] + 1)
			{
				swap(s[i - 1], s[i]);
			}
		}
	}
}
vector<int>  topological_sort(vector<vector<int>> &graph, string &s)
{
	int n = graph.size();
	vector<int> order;
	vector<int> deg(n);
	for(int i = 0; i < n; ++i)
	{
		for(int v : graph[i])
		{
			++deg[v];
		}
	}
	priority_queue<pair<int, int>> pq;
	for(int i = 0; i < n; ++i)
	{
		if(deg[i] == 0)
		{
			pq.push(make_pair(-s[i], i));
		}
	}
	while(pq.size())
	{
		int du, u;
		tie(du, u) = pq.top();
		pq.pop();
		order.push_back(u);
		for(int v : graph[u])
		{
			--deg[v];
			if(deg[v] == 0)
			{
				pq.push(make_pair(-s[v], v));
			}
		}
	}
	return order;
}
void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> nxt(26, n);
	vector<vector<int>> graph(n);
	for(int i = n - 1; i >= 0; --i)
	{
		int cur = s[i] - 'a';
		for(int x = 0; x < 26; ++x)
		{
			if((nxt[x] != n) && (x != cur + 1) && (x != cur - 1))
			{
				graph[i].push_back(nxt[x]);
			}
		}
		nxt[cur] = i;
	}
	vector<int> order = topological_sort(graph, s);
	int i = 0;
	string res = s;
	for(int index : order)
	{
		res[i] = s[index];
		++i;
	}
	cout << res << '\n';
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
