#include<bits/stdc++.h>
using namespace std;
#define ll long long
void rotate(vector<int> &a, int l, int r)
{
	--r;
	int prev = a[r];
	for(int i = l; i <= r; ++i)
	{
		int tmp = a[i];
		a[i] = prev;
		prev = tmp;
	}
}
void query1(vector<int> &a)
{
	cout << a.size() << endl;
	for(auto elem : a)
	{
		cout << elem <<  ' ';
	}
	cout << endl;
}
vector<int> query2(int m)
{
	vector<int> b(m);
	for(int i = 0; i < m; ++i)
	{
		cin >> b[i];
	}
	return b;
}
int get_mod(vector<int> &a, vector<int> &b, int k, int p)
{
	for(int i = k; i < k + p; ++i)
	{
		if(a[k] == b[i])
		{
			return (i - k);
		}
	}
	return 0;
}
void solve()
{
	vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23};
	int m = accumulate(primes.begin(), primes.end(), 0);
	vector<int> a(m);
	for(int i = 0; i < m; ++i)
	{
		a[i] = i + 1;
	}
	int i = 0;
	for(auto p : primes)
	{
		rotate(a, i, i + p);
		i += p;
	}
	query1(a);
	vector<int> b = query2(m);
	ll MOD = 1;
	for(auto p : primes)
	{
		MOD *= p;
	}
	cerr << m << ' ' << MOD << "\n";
	i = 0;
	ll ans = 0;
	for(auto p : primes)
	{
		int x = get_mod(a, b, i, p);
		i += p;

		ll mult = MOD / p;
		mult %= p;
		for(int i = 0; i < p; ++i)
		{
			if(((mult * i) % p) == x)
			{
				mult = (mult * i) % p;
				break;
			}
		}
		ans += mult;
		ans %= MOD;
	}
	cout << ans << '\n';
}
int main()
{
	solve();
	return 0;
}