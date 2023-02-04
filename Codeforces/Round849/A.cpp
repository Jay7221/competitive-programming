#include<bits/stdc++.h>
using namespace std;

void solve()
{
	char ch;
	cin >> ch;
	bool flag = false;
	for(char elem : "codeforces")
	{
		flag |= (elem == ch);
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