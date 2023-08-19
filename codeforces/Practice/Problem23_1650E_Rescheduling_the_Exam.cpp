#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
	int n, d;
	cin >> n >> d;
	vector<int> a(n + 2);
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	a[n + 1] = d + 1;
	vector<int> diff;
	for(int i = 1; i <= n + 1; ++i)
	{
		diff.push_back(a[i] - a[i - 1] - 1);
	}
	int last = diff[n];
	multiset<int> s;
	for(int i = 0; i < n; ++i)
	{
		s.insert(diff[i]);
	}
	auto erase = [&](int i)
	{
		s.erase(s.find(diff[i]));
		if(i + 1 < n)
		{
			s.erase(s.find(diff[i + 1]));
		}
	};
	auto insert = [&](int i)
	{
		s.insert(diff[i]);
		if(i + 1 < n)
		{
			s.insert(diff[i + 1]);
		}
	};
	auto addVal = [&](int k)
	{
		s.insert(k);
	};
	auto remVal = [&](int k)
	{
		s.erase(s.find(k));
	};
	auto getMin = [&]()
	{
		return *s.begin();
	};
	auto getMax = [&]()
	{
		return *(--s.end());
	};
	int ans = getMin();
	for(int i = 0; i < n; ++i)
	{
		erase(i);
		if(i < n - 1)
		{
			addVal(diff[i] + diff[i + 1] + 1);
			int mx = getMax();
			if((last - 1) >= ((mx - 1) / 2))
			{
				addVal(last - 1);
				ans = max(ans, getMin());
				remVal(last - 1);
			}
			else
			{
				remVal(mx);
				--mx;
				addVal(mx / 2);
				addVal(mx / 2 + mx % 2);
				ans = max(ans, getMin());
				remVal(mx / 2);
				remVal(mx / 2 + mx % 2);
				++mx;
				addVal(mx);
			}
			remVal(diff[i] + diff[i + 1] + 1);
		}
		else
		{
			last += diff[i] + 1;
			int mx = getMax();
			if((last - 1) >= ((mx - 1) / 2))
			{
				addVal(last - 1);
				ans = max(ans, getMin());
				remVal(last - 1);
			}
			else
			{
				remVal(mx);
				--mx;
				addVal(mx / 2);
				addVal(mx / 2 + mx % 2);
				ans = max(ans, getMin());
				remVal(mx / 2);
				remVal(mx / 2 + mx % 2);
				++mx;
				addVal(mx);
			}
			last -= diff[i];
		}
		insert(i);
	}
	cout << ans << '\n';
}
void solve1()
{
	int n, d;
	cin >> n >> d;
	vector<int> a(n + 2);
	vector<int> schedule;
	int mn = d + 2;
	int mn_pos = 0;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if(a[i] - a[i - 1] - 1 < mn)
		{
			mn = a[i] - a[i - 1] - 1;
			mn_pos = i;
		}
	}
	a[n + 1] = d + 1;
	auto cnt = [&]()
	{
		int mn = d + 2, mx = 0;
		for(int i = 1; i < n; ++i)
		{
			mn = min(mn, schedule[i] - schedule[i - 1] - 1);
			mx = max(mx, schedule[i] - schedule[i - 1] - 1);
		}
		return min(mn, max((mx - 1) / 2, d - schedule[n - 1] - 1));
	};
	for(int i = 0; i <= n; ++i)
	{
		if(i != mn_pos)
		{
			schedule.push_back(a[i]);
		}
	}
	int ans = cnt();
	if(mn_pos > 1)
	{
		schedule[mn_pos - 1] = a[mn_pos];
	}
	ans = max(ans, cnt());
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