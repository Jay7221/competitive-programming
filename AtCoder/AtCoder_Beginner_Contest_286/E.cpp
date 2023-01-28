#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll INF = 1e9 + 7;
void solve()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	vector<bool> vis(n);
	int dist[n][n];
	ll val[n][n];
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(i == j)
			{
				dist[i][j] = 0;
				val[i][j] = a[i];
			}
			else
			{
				dist[i][j] = INF;
				val[i][j] = 0;
			}
		}
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			char ch;
			cin >> ch;
			if(ch == 'Y')
			{
				if(i != j)
				{
					dist[i][j] = 1;
					val[i][j] = a[i] + a[j];
				}
			}
		}
	}


	for(int k = 0; k < n; ++k)
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					val[i][j] = val[i][k] + val[k][j] - a[k];
				}
				if(dist[i][j] == dist[i][k] + dist[k][j])
				{
					val[i][j] = max(val[i][j], val[i][k] + val[k][j] - a[k]);
				}
			}
		}
	}
	int q;
	cin >> q;
	while(q--)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		if(dist[u][v] == INF)
		{
			cout << "Impossible" << '\n';
		}
		else
		{
			cout << dist[u][v] << ' ' << val[u][v] << '\n';
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