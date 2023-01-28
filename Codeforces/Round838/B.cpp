#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cout << n << '\n';
	for(int i = 0; i < n; ++i)
	{
		int x = 1;
		while(x < a[i])
		{
			x = (2 * x + 1);
		}
		cout << (i + 1) << ' ' << (1 + (a[i] ^ x)) << '\n';
	}
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