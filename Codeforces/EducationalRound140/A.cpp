#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int x[3], y[3];
	for(int i = 0; i < 3; ++i)
	{
		cin >> x[i] >> y[i];
	}
	sort(x, x + 3);
	sort(y, y + 3);
	bool xflag = ((x[1] == x[0]) || (x[1] == x[2]));
	bool yflag = ((y[1] == y[0]) || (y[1] == y[2]));
	if(xflag && yflag)
	{
		cout << "NO\n";
	}
	else
	{
		cout << "YES\n";
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