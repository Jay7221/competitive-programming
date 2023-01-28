#include<bits/stdc++.h>
using namespace std;
#define ll int64_t
int MAX = 10000;
vector<int> primes;
vector<ll> factorize(ll n)
{
	vector<ll> factors;
	for(int i = 2; i <= sqrt(n); ++i)
	{
		while(n % i == 0)
		{
			n /= i;
			factors.push_back(i);
		}
	}
	return factors;
}
void pre()
{
	vector<bool> isPrime(MAX, true);
	for(int i = 2; i < MAX; ++i)
	{
		if(isPrime[i])
		{
			primes.push_back(i);
			for(int j = 2; i * j < MAX; ++j)
			{
				isPrime[i * j] = false;
			}
		}
	}
}
ll solve()
{
	ll n;
	cin >> n;
	ll k = (n & -n);
	double kk = k;
	double epsilon = 10;
	if((kk * (2 * kk - 1) >= n))
	{
		n /= k;
		if(n > 1)
		{
			return n;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return (2 * k);
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
		cout << solve() << '\n';
	}
	return 0;
}