#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	int x = 0, y = 0;
	bool flag = true;
	int base = 1;
	while(n)
	{
		int cur = n % 10;
		n /= 10;

		x += base * (cur / 2);
		y += base * (cur / 2);
		if(cur % 2)
		{
			if(flag)
			{
				x += base;
			}
			else
			{
				y += base;
			}
			flag ^= 1;
		}
		base *= 10;
	}
	cout << x << ' ' << y << '\n';
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