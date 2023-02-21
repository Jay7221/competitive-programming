#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	if(n % 2 == 0)
	{
		cout << "NO\n";
		return ;
	}
	else
	{
		cout << "YES\n";
	}
	int s = 2 * n + 1 - ((n - 1) / 2);
	for(int i = 1; i <= n; i += 2)
	{
		cout << i << ' ' << (s - i) << '\n';
		++s;
	}
	for(int i = 2; i <= n; i += 2)
	{
		cout << i << ' ' << (s - i) << '\n';
		++s;
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
	return 0;
}