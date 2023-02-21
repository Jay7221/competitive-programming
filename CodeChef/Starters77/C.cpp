#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	ll deficit = 0;
	for(int i = 0; i < n / 2; ++i)
	{
		deficit += abs(a[i] - a[n - 1 - i]);
	}
	bool flag;
	if(deficit == 0)
	{
		flag = true;
	}
	else
	{
		if(k == n)
		{
			flag = false;
		}
		else
		{
			if(k % 2 == 1)
			{
				flag = true;
			}
			else
			{
				if(deficit % 2 == 0)
				{
					flag = true;
				}
				else
				{
					if(n % 2 == 1)
					{
						flag = true;
					}
					else
					{
						flag = false;
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
