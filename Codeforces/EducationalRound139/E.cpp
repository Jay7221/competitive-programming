#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1), prev(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	auto decompose =[&](int l, int r)
	{
		vector<vector<int> > cur;
		for(int i = l; i <= r; ++i)
		{
			bool flag = true;
			for(auto &v : cur)
			{
				if(v.back() & a[i])
				{
					flag = false;
					v.push_back(a[i]);
				}
			}
			if(flag)
			{
				cur.push_back({a[i]});
			}
		}
		return cur.size();
	};
	vector<int> v;
	for(int i = 1; i <= n; ++i)
	{
		vector<int> nv;
		nv.push_back(i);
		for(auto ind : v)
		{
			if(a[ind] & a[i])
			{
				prev[i] = max(prev[i], ind);
				continue ;
			}
			nv.push_back(ind);
		}
		v = nv;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = i; j <= n; ++j)
		{
			ans += decompose(i, j);
		}
	}
	// cerr << ans << '\n';
	ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		ans += (i - prev[i]) * (n - i + 1);
	}
	cout << ans << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	while(t--)
	{
		solve();
	}
	return 0;
}