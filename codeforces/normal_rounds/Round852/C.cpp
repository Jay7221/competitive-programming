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
	int l = 0, r = n - 1;
	int mn = 1, mx = n;
	while(l < r)
	{
		if(a[l] == mn)
		{
			++l;
			++mn;
		}
		else if(a[l] == mx)
		{
			++l;
			--mx;
		}
		else if(a[r] == mn)
		{
			--r;
			++mn;
		}
		else if(a[r] == mx)
		{
			--r;
			--mx;
		}
		else
		{
			++l, ++r;
			cout << l << ' ' << r << '\n';
			return ;
		}
	}
	cout << -1 << '\n';
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