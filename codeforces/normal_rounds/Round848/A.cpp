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
	int sum = accumulate(a.begin(), a.end(), 0);
	int ans = sum - 2 * (a[0] + a[1]);
	for(int i = 0; i < n - 1; ++i)
	{
		int cur = a[i] + a[i + 1];
		ans = max(ans, sum - 2 * cur);
	}
	cout << ans << '\n';
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