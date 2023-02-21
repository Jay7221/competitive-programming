#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	vector<int> freqPre(n + 2), freqSuf(n + 2);
	for(int i = 1; i <= n;++i)
	{
		++freqPre[a[i]];
		++freqSuf[a[i]];
	}
	for(int i = 1; i <= n + 1; ++i)
	{
		freqPre[i] += freqPre[i - 1];
	}
	for(int i = n; i >= 0; --i)
	{
		freqSuf[i] += freqSuf[i + 1];
	}
	auto isIn = [&](int x, int l, int r)
	{
		return ((l <= x) && (x <= r));
	};
	auto check = [&](int x, int y)
	{
		if(x > y)
		{
			return false;
		}
		int rejected = freqPre[x - 1] + freqSuf[y + 1];
		int accepted = n - rejected;
		return ((accepted - rejected) >= k);
	};
	auto getAns = [&](int x, int y)
	{
		vector<int> pre(n + 1);
		for(int i = 1; i <= n; ++i)
		{
			if(isIn(a[i], x, y))
			{
				pre[i] = 1;
			}
			else
			{
				pre[i] = -1;
			}
			pre[i] += pre[i - 1];
		}
		int l = 1;
		int cur = pre[n] - k + 1;
		int len = 0;
		for(int i = 1; i <= n; ++i)
		{
			if(pre[i] == cur)
			{
				if((len == k - 1) && (i != n))
				{
					continue;
				}
				cout << l << ' ' << i << '\n';
				l = i + 1;
				++cur;
				++len;
			}
		}
	};
	int x = 0, y = n + 1;
	for(int i = 1; i <= n; ++i)
	{
		int l = x, r = n;
		while(l < r)
		{
			int m = (l + r) / 2;
			if(check(i, m))
			{
				r = m;
			}
			else
			{
				l = m + 1;
			}
		}
		int j = l;
		if(check(i, j))
		{
			if(j - i < y - x)
			{
				y = j;
				x = i;
			}
		}
	}
	cout << x << ' ' << y << '\n';
	getAns(x, y);
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
}