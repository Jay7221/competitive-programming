#include<iostream>
using namespace std;
void solve()
{
	long long x;
	cin >> x;
	x = x + 1;
	int ans = 0;
	while(x > 1)
	{
		x >>= 1;
		++ans;
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