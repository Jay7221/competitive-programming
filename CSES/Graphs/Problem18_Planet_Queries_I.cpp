#include<bits/stdc++.h>
using namespace std;
const int LOGMAX = 31;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	int prev[n][LOGMAX];
	for(int i = 0; i < n; ++i)
	{
		cin >> prev[i][0];
		--prev[i][0];
	}
	for(int k = 1; k < LOGMAX; ++k)
	{
		for(int i = 0; i < n; ++i)
		{
			prev[i][k] = prev[prev[i][k - 1]][k - 1];
		}
	}
	auto query = [&](int x, int k)
	{
		for(int i = 0; i < LOGMAX; ++i)
		{
			if((k >> i) & 1)
			{
				x = prev[x][i];
			}
		}
		return x;
	};
	while(q--)
	{
		int x, k;
		cin >> x >> k;
		--x;
		cout << (query(x, k) + 1) << '\n';
	}
	return 0;
}