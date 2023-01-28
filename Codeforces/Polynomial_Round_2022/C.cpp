#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int no[2] = {1, 1};
	for(int i = 0; i < n - 1; ++i)
	{
		int cur = s[i] - '0';
		no[cur] = i + 2;
		cout << min(no[0], no[1]) << ' ';
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