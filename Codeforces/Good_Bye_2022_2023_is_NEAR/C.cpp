#include<bits/stdc++.h>
using namespace std;
int MAX = 5000;
#define ll long long
vector<int> primes;
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
bool solve()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	map<int, set<int>> mp;
	for(int i = 0; i < n; ++i)
	{
		for(int j = i + 1; j < n; ++j)
		{
			if(a[i] == a[j])
			{
				return false;
			}
			ll d = abs(a[i] - a[j]);
			for(auto p : primes)
			{
				if(d % p)
				{
					continue;
				}
				mp[p].insert((p - (a[i] % p)) % p);
				mp[p].insert((p - (a[j] % p)) % p);
			}
		}
	}
	for(auto p : primes)
	{
		if(mp[p].size() >= p)
		{
			return false;
		}
	}
	return true;
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
		if(solve())
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}