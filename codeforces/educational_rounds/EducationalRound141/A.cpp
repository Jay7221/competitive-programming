#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	reverse(a.begin() + 1, a.end());
	int sum = 0;
	for(int i = 0; i < n; ++i)
	{
		if(a[i] == sum)
		{
			cout << "NO\n";
			return ;
		}
		sum += a[i];
	}
	cout << "YES\n";
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