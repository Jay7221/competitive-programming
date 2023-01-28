#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int a, b;
	cin >> a >> b;
	int ans = a - gcd(a, b);
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