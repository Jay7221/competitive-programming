#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
	for(int i = 2; i * i <= n; ++i)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}
void solve()
{
	int x, d;
	cin >> x >> d;
	int k = 0;
	while(x % d == 0)
	{
		++k;
		x /= d;
	}
	bool flag = false;
	if(k > 1)
	{
		if((x > 1) && !isPrime(x))
		{
			flag = true;
		}
		if((k > 2) && (!isPrime(d)))
		{
			if(k > 3)
			{
				flag = true;
			}
			else
			{
				for(int a = 2; a * a <= d; ++a)
				{
					if(d % a)
					{
						continue;
					}
					int b = d / a;
					if(((x * a) % d) || ((x * b) % d))
					{
						flag = true;
						break;
					}
				}
			}
		}
	}
	if(flag)
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

	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}

	return 0;
}