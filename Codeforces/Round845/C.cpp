#include<bits/stdc++.h>
using namespace std;
const int  MAX = 1e5 + 7;
const int INF = 1e9 + 7;
vector<int> factorize(int x)
{
	vector<int> ans;
	for(int i = 1; i * i <= x; ++i)
	{
		if((x % i) == 0)
		{
			ans.push_back(i);
		}
	}
	for(int i = ans.size() - 1; i > -1; --i)
	{
		int k = ans[i];
		if(k * k != x)
		{
			ans.push_back(x / k);
		}
	}
	return ans;
}
template<typename T>
void debug(T arr)
{
	for(auto elem : arr)
	{
		cerr << elem << ' ';
	}
	cerr << '\n';
}
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	set<int> s;
	vector<int> freq(m + 1);
	for(int i = 1; i <= m; ++i)
	{
		s.insert(i);
	}
	auto add = [&](int x)
	{
		for(auto f : factorize(x))
		{
			if(f > m)
			{
				break;
			}
			else
			{
				if(freq[f] == 0)
				{
					s.erase(f);
				}
				++freq[f];
			}
		}
	};
	auto rem = [&](int x)
	{
		for(auto f : factorize(x))
		{
			if(f > m)
			{
				break;
			}
			else
			{
				--freq[f];
				if(freq[f] == 0)
				{
					s.insert(f);
				}
			}
		}
	};
	int ans = INF;
	int l = -1, r = -1;
	for(int i = 0; i < n; ++i)
	{
		r = i;
		if(l == -1)
		{
			l = i;
		}
		add(a[i]);
		while(s.size() == 0)
		{
			ans = min(ans, a[r] - a[l]);
			rem(a[l]);
			++l;
		}
	}
	if(ans == INF)
	{
		ans = -1;
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