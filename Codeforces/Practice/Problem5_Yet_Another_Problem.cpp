#include<bits/stdc++.h>
using namespace std;
const int LOGMAX = 30;
template<typename T>
void debug(T &arr)
{
	for(auto elem : arr)
	{
		cerr << elem << ' ';
	}
	cerr << '\n';
}
void solve()
{
	int n, q;
	cin >> n >> q;
	int a[n + 2], pre[n + 2][LOGMAX];
	vector<int> preMax(n + 2, n + 1);
	for(int i = 0; i < n + 2; ++i)
	{
		a[i] = 0;
		for(int k = 0; k < LOGMAX; ++k)
		{
			pre[i][k] = 0;
		}
	}
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		for(int k = 0; k < LOGMAX; ++k)
		{
			pre[i][k] = (1 & (a[i] >> k));
			pre[i][k] += pre[i - 1][k];
		}
	}
	map<int, int> mp;
	int cur = 0;
	for(int i = n; i > 0; i -= 2)
	{
		cur ^= a[i + 1] ^ a[i];
		if(mp.find(cur) != mp.end())
		{
			preMax[i] = mp[cur];
		}
		mp[cur ^ a[i]] = i;
	}
	cur = 0;
	mp.clear();
	for(int i = n - 1; i > 0; i -= 2)
	{
		cur ^= a[i + 1] ^ a[i];
		if(mp.find(cur) != mp.end())
		{
			preMax[i] = mp[cur];
		}
		mp[cur ^ a[i]] = i;
	}



	auto sum = [&](int l, int r, int k)
	{
		return (pre[r][k] - pre[l - 1][k]);
	};
	auto check1 = [&](int l, int r)
	{
		for(int k = 0; k < LOGMAX; ++k)
		{
			if(sum(l, r, k) % 2)
			{
				return false;
			}
		}
		return true;
	};
	auto check2 = [&](int l, int r)
	{
		for(int k = 0; k < LOGMAX; ++k)
		{
			if(sum(l, r, k) > 0)
			{
				return false;
			}
		}
		return true;
	};
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		if(!check1(l, r))
		{
			cout << -1 << '\n';
			continue;
		}
		if(check2(l, r))
		{
			cout << 0 << '\n';
			continue;
		}
		if((r - l + 1) % 2)
		{
			cout << 1 << '\n';
			continue;
		}
		if(a[l] == 0 || a[r] == 0)
		{
			cout << 1 << '\n';
			continue;
		}
		if(preMax[l] > r)
		{
			cout << -1 << '\n';
			continue;
		}
		cout << 2 << '\n';
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}