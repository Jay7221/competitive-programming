#include<iostream>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	int cur = 0;
	for(int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		cur = (cur xor a);
	}
	bool flag = true;
	if((n % 2 == 0) && (cur > 0))
	{
		flag = false;
	}
	if(flag)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
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