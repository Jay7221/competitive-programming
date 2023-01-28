#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum = (sum + a[i]) % 2;
	}
	if(sum == 0)
	{
		cout << 0 << '\n';
		return ;
	}
	int ans = 30;
	for(auto elem : a)
	{
		int cnt = 0;
		int cur = elem;
		while((cur > 0) && ((elem % 2 == cur % 2)))
		{
			++cnt;
			cur /= 2;
		}
		if(cur % 2 != elem % 2)
		{
			ans = min(ans, cnt);
		}
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