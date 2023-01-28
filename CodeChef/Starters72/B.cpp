#include<bits/stdc++.h>
using namespace std;
#define ll int64_t
ll power(ll a, int p)
{
	ll ans = 1, res = a;
	while(p)
	{
		if(p & 1)
		{
			ans = ans * res;
		}
		res = res * res;
		p >>= 1;
	}
	return ans;
}
void solve()
{
	ll n, s, k;
	cin >> n >> k >> s;
	vector<int> b(n);
	ll s_cur = s;
	auto get = [&](int t, ll s)
	{
		ll mod = power(k, t);
		ll kt1 = power(k, t - 1);
		ll ss = s % mod;
		if(ss == kt1)
		{
			return 1;
		}
		if(ss == 0)
		{
			return 0;
		}
		if(ss == mod - kt1)
		{
			return -1;
		}
		return -2;
	};
	for(int i = 0; (i < n) && (s_cur > 0); ++i)
	{
		if(s_cur < power(k, i))
		{
			break ;
		}
		b[i] = get(i + 1, s_cur);
		if(b[i] == -2)
		{
			break;
		}
		s_cur -= b[i] * power(k, i);
	}
	if(s_cur > 0)
	{
		cout << -2 << '\n';
	}
	else
	{
		for(int i = 0; i < n; ++i)
		{
			cout << b[i] << ' ';
		}
		cout << '\n';
	}
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