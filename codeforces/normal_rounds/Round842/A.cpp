#include<iostream>
using namespace std;
void solve()
{
	int k;
	cin >> k;
	cout << k - 1 << '\n';
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