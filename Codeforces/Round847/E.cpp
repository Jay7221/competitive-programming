#include<bits/stdc++.h>
using namespace std;


void solve()
{
	int x;
	cin >> x;
	int a, b;
	a = b = 0;
	a |= x;
	if(x % 2)
	{

		cout << -1 << '\n';
		return;
	}
	if((x & (x / 2)) > 0)
	{
		cout << -1 << '\n';
		return;
	}
	a |= (x / 2);
	b |= (x / 2);
	cout << a << ' ' << b << '\n';
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