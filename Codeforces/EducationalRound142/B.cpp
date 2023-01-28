#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans = 0;
	int sum = a + b + c + d;
	if(a > 0)
	{
		int tmp = sum;
		tmp = min(tmp, a + b + min(c, a + b + 1));
		tmp = min(tmp, a + c + min(b, a + c + 1));
		ans = max(ans, tmp);
		if(min(a + b - c, a + c - b) >= 0)
		{
			int tmp = sum;
			tmp = min(tmp, a + b + c + min(d, a + b - c + 1));
			tmp = min(tmp, a + b + c + min(d, a - b + c + 1));
			ans = max(ans, tmp);
		}
	}
	else
	{
		ans = min(1, a + b + c + d);
	}
	cout << ans << '\n';
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