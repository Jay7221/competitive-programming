#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	int a[n][n];
	bool flag1 = true, flag2 = true;
	int l = 1, r  = n * n;
	for(int i = 0; i < n; ++i)
	{
		if(flag1)
		{
			for(int j = n - 1; j >= 0; --j)
			{
				if(flag2)
				{
					a[i][j] = l;
					++l;
				}
				else
				{
					a[i][j] = r;
					--r;
				}
				flag2 ^= 1;
			}
		}
		else
		{
			for(int j = 0; j < n; ++j)
			{
				if(flag2)
				{
					a[i][j] = l;
					++l;
				}
				else
				{
					a[i][j] = r;
					--r;
				}
				flag2 ^= 1;
			}
		}
		flag1 = (flag1 ^ 1);
	}
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cout << a[i][j] << ' ';
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