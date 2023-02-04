#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool flag = false;
	int x = 0, y = 0;
	for(int i = 0; i < n; ++i)
	{
		x += (s[i] == 'R') - (s[i] == 'L');
		y += (s[i] == 'U') - (s[i] == 'D');
		flag |= ((x == 1) && (y == 1));
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