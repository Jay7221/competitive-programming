#include<iostream>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	for(int i = 2; i * i < n; ++i)
	{
		if(n % i)
		{
			continue ;
		}
		cout << 1 << ' ' << i << ' ' << (n / i) << '\n';
		return ;
	}
	cout << -1 << '\n';
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