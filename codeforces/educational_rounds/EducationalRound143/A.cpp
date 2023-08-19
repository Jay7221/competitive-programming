#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	reverse(b.begin(), b.end());
	string s = a + b;
	int cnt = 0;
	for(int i = 1; i < s.size(); ++i)
	{
		cnt += (s[i - 1] == s[i]);
	}
	if(cnt <= 1)
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
