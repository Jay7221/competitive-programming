#include<iostream>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 0; i < n- 1; ++i)
	{
		if((a[i] + a[i + 1]) % 2 == 0)
		{
			++ans;
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