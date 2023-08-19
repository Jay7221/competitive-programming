#include<iostream>
using namespace std;
const int MAX = (1 << 10) - 1;
void solve()
{
	int n;
	cin >> n;
	int mx = 0, mn = MAX;
	for(int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		mx = (mx | a);
		mn = (mn & a);
	}
	cout << (mx - mn) << '\n';
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