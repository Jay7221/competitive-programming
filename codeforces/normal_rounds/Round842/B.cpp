#include<iostream>
using namespace std;
void solve()
{
	int n, k;
	cin >> n >> k;
	int p[n];
	for(int i = 0; i < n; ++i)
	{
		cin >> p[i];
	}
	int cur = 1, ans = 0;
	for(int i = 0; i < n; ++i)
	{
		if(p[i] == cur)
		{
			++cur;
		}
		else
		{
			++ans;
		}
	}
	ans = (ans + k - 1) / k;
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