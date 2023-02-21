#include<bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	cin >> s;
	for(char &elem : s)
	{
		elem = '0' + (1 ^ (elem - '0'));
	}
	cout << s << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	t = 1;
	while(t--)
	{
		solve();
	}

	return 0;
}