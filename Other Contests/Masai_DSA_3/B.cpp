#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n, m;
	cin >> n >> m;
	ll m1[n][m], m2[n][m];
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j< m; ++j)
		{
			cin >> m1[i][j];
		}
	}
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j< m; ++j)
		{
			cin >> m2[i][j];
		}
	}
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j< m; ++j)
		{
			m1[i][j] = m1[i][j] + m2[i][j];
		}
	}
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j< m; ++j)
		{
			cout << m1[i][j] << ' ';
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