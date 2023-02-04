#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	if(n % 2)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << 1 << ' ' << (n / 2) << '\n';
	}
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
}