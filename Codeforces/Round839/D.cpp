#include<iostream>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int l = 0, r = 1e9;
	for(int i = 1; i < n; ++i)
	{
		if(a[i - 1] < a[i])
		{
			r = min(r, (a[i] + a[i - 1]) / 2);
		}
		else if(a[i - 1] > a[i])
		{
			l = max(l, (a[i - 1] + a[i] + 1) / 2);
		}
	}
	if(l > r)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << l << '\n';
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