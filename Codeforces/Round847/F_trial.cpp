
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
vector<vector<int>> graph;
void dfs(int u, int p, vector<int> &tour)
{
	tour.push_back(u);
	for(auto v : graph[u])
	{
		if(v != p)
		{
			dfs(v, u, tour);
			tour.push_back(u);
		}
	}
}
void solve()
{
	int n;
	cin >> n;
	graph.assign(n, vector<int>());
	vector<int> c(n), t(n), score(n, INF);
	for(int i = 0; i < n; ++i)
	{
		cin >> c[i];
		--c[i];
		t[c[i]] = i;
	}
	for(int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> v;
	dfs(c[0], -1, v);
	int m = v.size();
	vector<int> tv(m);
	for(int i = 0; i < m; ++i)
	{
		tv[i] = t[v[i]];
	}
	for(int i = 0; i < m; ++i)
	{
		cerr << v[i] + 1<< ' ';
	}
	cerr << '\n';
	for(int i = 0; i < m; ++i)
	{
		cerr << tv[i] << ' ';
	}
	cerr << '\n';
	tv[0] = tv[m - 1] = -1;
	vector<int> left(m), right(m);
	stack<int> st;
	st.push(0);
	for(int i = 1; i < m - 1; ++i)
	{
		while(tv[i] <= tv[st.top()])
		{
			st.pop();
		}
		left[i] = st.top();
		st.push(i);
	}
	while(st.size())
	{
		st.pop();
	}
	st.push(m - 1);
	for(int i = m - 2; i > 0; --i)
	{
		while(tv[i] <= tv[st.top()])
		{
			st.pop();
		}
		right[i] = st.top();
		st.push(i);
	}

	for(int i = 1; i < m - 1; ++i)
	{
		score[tv[i]] = min(score[tv[i]], min(i - left[i], right[i] - i));
	}
	for(int i = 1; i < n; ++i)
	{
		score[i] = min(score[i], score[i - 1]);
		cout << score[i] << ' ';
	}
	cout << "\n";
	for(int i = 0; i < m; ++i)
	{
		cerr << left[i] << ' ';
	}
	cerr << '\n';
	for(int i = 0; i < m; ++i)
	{
		cerr << right[i] << ' ';
	}
	cerr << '\n';
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