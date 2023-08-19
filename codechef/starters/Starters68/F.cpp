#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<set>
using namespace std;
void solve()
{
	auto debug = [&](vector<int> &a)
	{
		for(auto elem : a)
		{
			cerr << elem << ' ';
		}
		cerr << '\n';
	};


	int n;
	cin >> n;
	vector<int> a(n + 1), p(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i)
	{
		if(a[i] >= i)
		{
			cout << -1 << '\n';
			return ;
		}
	}
	vector<vector<int> > graph(n + 1);
	vector<int> degree(n + 1);
	vector<int> s;
	for(int i = 1; i <= n; ++i)
	{
		if(a[i] != -1)
		{
			if(a[i] > 0)
			{
				graph[i].push_back(a[i]);
				++degree[a[i]];
			}
			while(s.size() && (s.back() > a[i]))
			{
				int j = s.back();
				s.pop_back();
				graph[j].push_back(i);
				++degree[i];
			}
		}
		s.push_back(i);
	}
	vector<bool> vis(n + 1);
	set<int> st;
	for(int i = 0; i <= n; ++i)
	{
		if(degree[i] == 0)
		{
			vis[i] = 1;
			st.insert(i);
		}
	}
	vector<int> topological;
	while(st.size())
	{
		int u = *st.begin();
		st.erase(st.begin());
		topological.push_back(u);
		for(auto child : graph[u])
		{
			--degree[child];
			if(degree[child] == 0)
			{
				st.insert(child);
				vis[child] = 1;
			}
		}
	}
	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			cout << -1 << '\n';
			return ;
		}
	}
	int cur = 1;
	for(auto elem : topological)
	{
		if(elem == 0)
		{
			continue ;
		}
		p[elem] = cur;
		++cur;
	}
	for(int i = 1; i <= n; ++i)
	{
		cout << p[i] << ' ' ;
	}
	cout << '\n';
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