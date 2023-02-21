#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int MAX = 1e6 + 7;
	int n;
	cin >> n;
	vector<int> a(n);
	vector<bool> isInA(MAX);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		isInA[a[i]] = true;
	}
	for(int d = MAX - 1; d > 0; --d)
	{
		if(isInA[d])
		{
			continue;
		}
		int ans = 0;
		for(int x = 2 * d; x < MAX; x += d)
		{
			if(isInA[x])
			{
				ans = gcd(ans, x);
			}
		}
		isInA[d] = (ans == d);
	}
	int ans = accumulate(isInA.begin(), isInA.end(), 0) - n;
	cout << ans << '\n';
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
