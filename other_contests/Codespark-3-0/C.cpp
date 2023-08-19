#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	int sz = 32;
	long long ans = 0;
	vector<int> even(sz), odd(sz);
	for(int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		int curEven = 0;
		for(int i = 0; i < 5; i += 2)
		{
			int x = s[i] - '0';
			x /= 2;
			curEven = (curEven | (1 << x));
		}
		for(int i = 0; i < sz; ++i)
		{
			if(__builtin_popcount(curEven | i) == 3)
			{
				ans = ans + odd[i];
			}
		}
		int curOdd = 0;
		for(int i = 1; i < 5; i += 2)
		{
			int x = s[i] - '0';
			x /= 2;
			curOdd = (curOdd | (1 << x));
		}
		for(int i = 0; i < sz; ++i)
		{
			if(__builtin_popcount(curOdd | i) == 3)
			{
				ans = ans + even[i];
			}
		}
		++even[curEven];
		++odd[curOdd];
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