#include<bits/stdc++.h>
using namespace std;
vector<int> primes;
const int MAX = 1e5 + 7;
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
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> freq;
	bool flag = true;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		++freq[a[i]];
		if((a[i] > 1) && freq[a[i]] > 1)
		{
			flag = false;
		}
	}
	map<int, bool> vis;
	if(flag)
	{
		for(auto elem : a)
		{
			for(auto p : primes)
			{
				if(p > elem)
				{
					break ;
				}
				if(elem % p == 0)
				{
					if(vis[p])
					{
						flag = false;
						break ;
					}
					vis[p] = 1;
					while(elem % p == 0)
					{
						elem /= p;
					}
				}
			}
			if(elem > 1)
			{
				if(vis[elem])
				{
					flag = false;
				}
				vis[elem] = 1;
			}
			if(!flag)
			{
				break ;
			}
		}
	}
	if(!flag)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
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