#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	map<ll, set<int>> ind;
	for(int i = 1; i < n; ++i)
	{
		for(int j = 0; j < i; ++j)
		{
			int diff = a[i] - a[j];
			for(int s = 1; s * s <= diff; ++s)
			{
				if(diff % s)
				{
					continue ;
				}
				int t = diff / s;
				if((s + t) % 2)
				{
					continue;
				}
				ll p = (s + t) / 2;
				ll x = p * p - a[i];
				if(x < 0)
				{
					continue;
				}
				ind[x].insert(i);
				ind[x].insert(j);
			}
		}
	}
	int ans = 1;
	for(auto [p, q] : ind)
	{
		if(q.size() > ans)
		{
			ans = q.size();
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