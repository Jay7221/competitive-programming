#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	vector<vector<int>> pre(n + 1, vector<int>(n + 1));
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			char ch;
			cin >> ch;
			pre[i][j] = (ch == '*');
		}
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			pre[i][j] += pre[i][j - 1];
		}
		for(int j = 1; j <= n; ++j)
		{
			pre[i][j] += pre[i - 1][j];
		}
	}
	while(q--)
	{
		int i1, j1, i2, j2;
		cin >> i1 >> j1 >> i2 >> j2;
		--i1, --j1;
		int ans = pre[i1][j1] + pre[i2][j2] - pre[i1][j2] - pre[i2][j1];
		cout << ans << '\n';
	}
	return 0;
}