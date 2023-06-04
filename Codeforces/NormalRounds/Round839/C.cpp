#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int k, n;
	cin >> n >> k;
	vector<int> a(n, 1);
	k -= n;
	a[0] = 0;
	for(int i = 1; i < n - 1; ++i)
	{
		int tmp = min(k, a[i - 1] + 1 - a[i]);
		a[i] += tmp;
		k -= tmp;
	}
	a[0] = 1;
	a[n - 1] += k;
	for(int i = 1; i < n; ++i)
	{
		a[i] += a[i - 1];
	}
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << ' ';
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