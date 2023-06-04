#include<bits/stdc++.h>
using namespace std;
vector<int> primes;
const int MAX = 1e4 + 7;
const int INF = 1e9 + 7;
void pre()
{
	vector<bool> isPrime(MAX, 1);
	for(int i = 2; i < MAX; ++i)
	{
		if(isPrime[i])
		{
			primes.push_back(i);
			for(int j = 2; i * j < MAX; ++j)
			{
				isPrime[i * j] = 0;
			}
		}
	}
}
void solve()
{
	auto factorize = [&](int n)
	{
		vector<int> factors;
		for(auto p : primes)
		{
			if(n < p)
			{
				break ;
			}
			if(n % p == 0)
			{
				factors.push_back(p);
				while(n % p == 0)
				{
					n /= p;
				}
			}
		}
		if(n > 1)
		{
			factors.push_back(n);
		}
		return factors;
	};
	auto calc = [&](int x, int p)
	{
		return ((p - (x % p)) % p);
	};
	int x, y;
	cin >> x >> y;
	int ans = INF;
	for(auto p : factorize(y - x))
	{
		ans = min(ans, calc(x, p));
	}
	if(ans == INF)
	{
		ans = -1;
	}
	cout << ans << '\n';
	return ;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pre();
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}