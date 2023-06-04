#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> a(n);
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n - 1; ++j)
		{
			int pij;
			cin >> pij;
			a[i].push_back(pij);
		}
	}
	sort(a.begin(), a.end());
	vector<int> p(n);
	if(a[0][0] != a[1][0])
	{
		p[0] = a[1][0];
		for(int i = 1; i < n; ++i)
		{
			p[i] = a[0][i - 1];
		}
	}
	else
	{
		p[0] = a[0][0];
		for(int i = 1; i < n; ++i)
		{
			p[i] = a[n - 1][i - 1];
		}
	}
	for(int i = 0; i < n; ++i)
	{
		cout << p[i] << ' ';
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