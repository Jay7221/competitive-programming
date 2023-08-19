#include<iostream>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	int freq = 0;
	for(int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		freq += (a == 1);
	}
	int ans = n - (freq / 2);
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