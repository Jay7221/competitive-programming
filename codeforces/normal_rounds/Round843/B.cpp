#include<iostream>
using namespace std;
#define ll long long
ll MAX = 1e18;
void solve()
{
	ll x, y;
	cin >> x >> y;
	ll n = (max(2ll, x) * max(2ll, y)) - (x + y);
	if(n == 0)
	{
		n = 8;
	}
	cout << n << '\n';
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