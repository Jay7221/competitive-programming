#include<bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	long long ans = 1, val = 1;
	for(int i = 1; i < n; ++i)
	{
		if(s[i] == s[i - 1])
		{
			val = (val * 2) % MOD;
		}
		else
		{
			val = 1;
		}
		ans = (ans + val) % MOD;
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