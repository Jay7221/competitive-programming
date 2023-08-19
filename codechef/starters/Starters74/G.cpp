#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> graph;
vector<ll> par, dep;
vector<ll> a, power;
vector<bool> vis;
ll n, x;
ll INF = 1e15 + 7;


void dfs(ll u)
{
	vis[u] = true;
	power[u] = a[u];
	for(auto v : graph[u])
	{
		if(vis[v])
		{
			par[u] = v;
		}
		else
		{
			dfs(v);
			power[u] = max(power[u], power[v]);
		}
	}
}
template<typename T>
void debug(T &v)
{
	for(auto elem : v)
	{
		cerr << elem << ' ';
	}
	cerr << '\n';
}

bool check(ll u, ll m, vector<ll> &nodes, vector<ll> &pre)
{
	ll n = nodes.size();
	ll l = 0, r = nodes.size() - 1;
	while(l < r)
	{
		ll mid = (l + r) / 2;
		if(nodes[mid] < power[u] + m)
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	ll sum = (power[u] + m) * 1ll * (n - l);
	sum -= pre[n - 1] - pre[l - 1];
	if(sum < x)
	{
		return false;
	}
	return true;
}
ll get(ll u, vector<ll> &nodes, vector<ll> &pre)
{
	ll l = 0, r = x;
	while(l < r)
	{
		ll m = (l + r) / 2;
		if(check(u, m, nodes, pre))
		{
			r = m;
		}
		else
		{
			l = m + 1;
		}
	}
	return l;
}

ll dfs(ll u, vector<ll> &nodes, vector<ll> &pre)
{
	nodes.push_back(power[u]);
	pre.push_back(pre.back() + power[u]);

	ll ans = get(u, nodes, pre);
	for(auto v : graph[u])
	{
		if(v != par[u])
		{
			ans = min(ans, dfs(v, nodes, pre));
		}
	}

	nodes.pop_back();
	pre.pop_back();


	return ans;
}
void solve()
{
	cin >> n >> x;
	graph.assign(n, vector<ll>());
	par.assign(n, -1);
	dep.assign(n, 0);
	a.assign(n, 0);
	power.assign(n, 0);
	vis.assign(n, false);
	

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n - 1; ++i)
	{
		ll u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i = 0; i < n; ++i)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
	x -= accumulate(power.begin(), power.end(), 0ll);
	vector<ll> nodes;
	vector<ll> prefix_sum;
	nodes.push_back(INF);
	prefix_sum.push_back(INF);
	cout << dfs(0, nodes, prefix_sum) << '\n';
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