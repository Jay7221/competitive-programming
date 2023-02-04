#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> factorize(int n)
{
	vector<pair<int, int>> factors;
	for(int i = 2; i * i <= n; ++i)
	{
		if(n % i)
		{
			continue;
		}
		int cnt = 0;
		while(n % i == 0)
		{
			++cnt;
			n /= i;
		}
		factors.push_back({i, cnt});
	}
	if(n > 1)
	{
		factors.push_back({n, 1});
	}
	return factors;
}

void solve()
{
	int n;
	cin >> n;
	vector<pair<int, int>> factors = factorize(n);
	int ans = 0;
	bool flag = true;
	while(flag)
	{
		flag = false;
		int cur = 1;
		for(auto &[p, np] : factors)
		{
			if(np > 0)
			{
				--np;
				cur *= p;
				flag = true;
			}
		}
		if(cur > 1)
		{
			flag = true;
			ans += cur;
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
}