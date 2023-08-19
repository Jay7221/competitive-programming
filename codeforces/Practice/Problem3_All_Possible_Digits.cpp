#include<bits/stdc++.h>
using namespace std;
template<typename T>
void debug(T &arr)
{
	for(auto elem : arr)
	{
		cerr << elem << ' ' ;
	}
	cerr << '\n';
}
void solve()
{
	int n, p;
	cin >> n >> p;
	auto sub = [&](int a, int b)
	{
		int ans = (a - b + p) % p;
		return ans;
	};
	vector<int> a(n + 1);
	set<int> s;
	for(int i = n - 1; i >= 0; --i)
	{
		cin >> a[i];
		s.insert(a[i]);
	}
	int mx = p - 1, mn = 0;
	auto update = [&]()
	{
		vector<int> v;
		for(auto c : s)
		{
			v.push_back(c);
		}
		for(auto elem : v)
		{
			mn += (mn == elem);
		}
		for(int i = v.size() - 1; i > -1; --i)
		{
			mx -= (mx == v[i]);
		}
	};
	int ans = p - 1;
	update();
	if(mn > a[0])
	{
		ans = max(0, mx - a[0]);
	}
	else
	{
		ans = p - a[0];
		int cur = 1;
		for(int i = 1; i <= n; ++i)
		{
			a[i] += cur;
			cur = a[i] / p;
			a[i] %= p;
			s.insert(a[i]);
		}
		mx = a[0] - 1;
		update();
		ans += max(0, mx);
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