#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int INF = 1e9 + 7;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int cur = a[n - 1] | a[0];
	for(int k = 30; k >= 0; --k)
	{
		int mx = 0;
		for(int i = 0; i <= min(mx, n - 1); ++i)
		{
			int tmp = (cur ^ (cur | a[i]));
			tmp >>= k;
			if(tmp == 0)
			{
				mx = max(mx, i + a[i]);
			}
		}
		if(mx < n - 1)
		{
			cur |= (1 << k);
		}
	}
	int MAX = 0;
	for(int i = 0; i < n; ++i)
	{
		MAX = (MAX | a[i]);
	}
	if(cur > MAX)
	{
		cur = -1;
	}
	cout << cur << '\n';
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