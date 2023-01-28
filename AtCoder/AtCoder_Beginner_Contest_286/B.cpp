#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	string t;
	for(int i = 0; i < n; ++i)
	{
		if((i + 1 < n) && (s[i] == 'n') && (s[i + 1] == 'a'))
		{
			t += "nya";
			++i;
		}
		else
		{
			t.push_back(s[i]);
		}
	}
	cout << t << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}