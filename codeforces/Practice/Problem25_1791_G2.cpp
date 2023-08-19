#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n, c;
	cin >> n >> c;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	vector<ll> v(n);
	vector<pair<ll, ll>> v_p(n);
	for(int i = 0; i < n; ++i)
	{
		v[i] = a[i] + min(i + 1, n - i);
		v_p[i] = {v[i], i};
	}
	sort(v_p.begin(), v_p.end());
	sort(v.begin(), v.end());
	for(int i = 1; i < n; ++i)
	{
		v[i] += v[i - 1];
	}
	auto check = [&](int no_tel, int coins)
	{
		if(no_tel == 0)
		{
			return true;
		}
		return (coins >= v[no_tel - 1]);
	};
	auto get = [&](int x)
	{
		int l = 0, r = n;
		while(l < r)
		{
			int m = (l + r + 1) / 2;
			if(check(m, x))
			{
				l = m;
			}
			else
			{
				r = m - 1;
			}
		}
		return l;
	};
	int ans = 0;
	int cur = 0;
	for(auto [cost, ind] : v_p)
	{
		++cur;
		int curCost = a[ind] + ind + 1;
		if(c < curCost)
		{
			continue;
		}
		int k = get(c - curCost);
		if(k >= cur)
		{
			k = get(c - curCost + cost);
			ans = max(ans, k);
		}
		else
		{
			ans = max(ans, k + 1);
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