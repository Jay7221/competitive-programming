#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	if(count(a.begin(), a.end(), '0') == count(b.begin(), b.end(), '0'))
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