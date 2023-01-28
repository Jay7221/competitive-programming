#include<iostream>
#include<vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	if(n == 3)
	{
		cout << "NO\n";
		return ;
	}
	cout << "YES\n";
	vector<int> a(n);
	if(n % 2 == 1)
	{
		int k = n / 2;
		for(int i = 0; i < n; i += 2)
		{
			a[i] = -(k - 1);
		}
		for(int i = 1; i < n; i += 2)
		{
			a[i] = k;
		}
	}
	else
	{
		int cur = 1;
		for(int i = 0; i < n; ++i)
		{
			a[i] = cur;
			cur *= -1;
		}
	}
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << '\n';
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