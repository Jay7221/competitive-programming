#include<bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
#define ll long long
vector<int> a;
vector<vector<int>> graph;

int add(int a, int b)
{
	ll ans = a;
	ans = (ans + b) % MOD;
	return ans;
}
int mult(int a, int b)
{
	ll ans = a;
	ans = (ans * b) % MOD;
	return ans;
}
int powm(int a, int p)
{
	ll ans = 1, res = a;
	while(p)
	{
		if(p & 1)
		{
			ans = mult(ans, res);
		}
		res = mult(res, res);
		p >>= 1;
	}
	return ans;
}
int inv(int x)
{
	return powm(x, MOD - 2);
}
int eval(vector<int> &v)
{
	int ans = 0, cur = 0;
	for(auto elem : v)
	{
		cur ^= elem;
	}
	for(auto elem : v)
	{
		ans = max(ans, cur ^ elem);
	}
	return ans;
}
int merge(vector<int> &v)
{
	int q = v.size();
	int ans = 0;
	for(auto elem : v)
	{
		ans = add(ans, elem);
	}
	ans = mult(ans, inv(q));
	return ans;
}
int dfs(int u, int p, vector<int> &path)
{
	path.push_back(a[u]);
	bool flag = true;
	vector<int> paths;
	for(auto v : graph[u])
	{
		if(v != p)
		{
			paths.push_back(dfs(v, u, path));
		}
	}
	int ans;
	if(paths.size())
	{
		ans = merge(paths);
	}
	else
	{
		ans = eval(path);
	}
	path.pop_back();
	return ans;
}
int dfs2(int u, int p, int curXor, int curForget)
{
	if((a[u] ^ curXor) > (curForget ^ curXor))
	{
		curForget = a[u];
	}
	bool flag = true;
	vector<int> paths;
	for(auto v : graph[u])
	{
		if(v != p)
		{
			paths.push_back(dfs2(v, u, (curXor ^ a[v]), curForget));
		}
	}
	if(paths.size())
	{
		return merge(paths);
	}
	else
	{
		return (curXor ^ curForget);
	}
}
void solve()
{
	int n;
	cin >> n;
	graph.assign(n, vector<int>());
	a.assign(n, 0);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> path;
	cout << dfs2(0, -1, a[0], a[0]) << '\n';
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