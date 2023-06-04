#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 2), index(n + 2);
	index[0] = n + 1;
	index[n + 1] = 0;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		index[a[i]] = i;
	}
	int cur = 0;
	int l, r;
	int ans = (n + 1) / 2;
	if(n % 2)
	{
		int mid = (n + 1) / 2;
		l = r = mid;
	}
	else
	{
		l = n / 2;
		r = l + 1;
	}
	while(index[l] <= index[r])
	{
		--ans;
		if((index[l - 1] < index[l]) && (index[r] < index[r + 1]))
		{
			--l;
			++r;
		}
		else
		{
			break;
		}
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