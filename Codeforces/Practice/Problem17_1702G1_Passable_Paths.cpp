#include<bits/stdc++.h>
using namespace std;
const int LOGMAX = 30;
vector<int> depth;
vector<vector<int>> graph, parent;


template<typename T>
void debug(T &arr)
{
	for(auto elem : arr)
	{
		cerr << elem << ' ';
	}
	cerr << '\n';
}
void dfs(int node, int p)
{
	parent[node][0] = p;
	for(int child : graph[node])
	{
		if(child != parent[node][0])
		{
			depth[child] = depth[node] + 1;
			dfs(child, node);
		}
	}
}
int getAncestor(int u, int d)
{
	int ans = u;
	for(int k = 0; k < LOGMAX; ++k)
	{
		if(1 & (d >> k))
		{
			ans = parent[ans][k];
		}
	}
	return ans;
}
int lca(int u, int v)
{
	if(depth[u] > depth[v])
	{
		swap(u, v);
	}
	int diff = depth[v] - depth[u];
	v = getAncestor(v, diff);
	if(u == v)
	{
		return u;
	}
	for(int k = LOGMAX - 1; k > -1; --k)
	{
		int uu = parent[u][k], vv = parent[v][k];
		if((uu == -1) || (vv == -1))
		{
			continue;
		}
		if(uu != vv)
		{
			u = uu;
			v = vv;
		}
	}
	return parent[u][0];
}
bool cmp(int u, int v)
{
	return (depth[u] < depth[v]);
}
void solve()
{
	int n;
	cin >> n;
	graph.assign(n, vector<int>());
	parent.assign(n, vector<int>(LOGMAX, -1));
	depth.assign(n, 0);
	for(int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0, 0);
	for(int k = 1; k < LOGMAX; ++k)
	{
		for(int i = 0; i < n; ++i)
		{
			int ii = parent[i][k - 1];
			if(ii != -1)
			{
				parent[i][k] = parent[ii][k - 1];
			}
		}
	}
	int q;
	cin >> q;
	while(q--)
	{
		int m;
		cin >> m;
		vector<int> v(m);
		for(int i = 0; i < m; ++i)
		{
			cin >> v[i];
			--v[i];
		}
		sort(v.begin(), v.end(), cmp);
		reverse(v.begin(), v.end());
		bool flag = true;
		int end1 = -1, end2 = -1, mid = -1;
		for(auto elem : v)
		{
			if(end1 == -1)
			{
				end1 = elem;
			}
			else
			{
				int tmp = lca(elem, end1);
				if(tmp != elem)
				{
					if(mid == -1)
					{
						mid = tmp;
						end2 = elem;
					}
					else
					{
						if(mid != tmp)
						{
							flag = false;
							break;
						}
						else
						{
							if(lca(end2, elem) != elem)
							{
								flag = false;
								break;
							}
						}
					}
				}
			}
		}
		if(mid != -1)
		{
			for(auto elem : v)
			{
				if(depth[elem] < depth[mid])
				{
					flag = false;
					break;
				}
			}
		}
		if(flag)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
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