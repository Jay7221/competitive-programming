#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(count(s.begin(), s.end(), s[0]) == 2 * n)
	{
		cout << -1 << '\n';
		return ;
	}
	vector<int> v;
	char ch;
	if(count(s.begin(), s.end(), '0') >= n)
	{
		ch = '0';
	}
	else
	{
		ch = '1';
	}
	for(int i = 0; (i < 2 * n) && v.size() < n; ++i)
	{
		if(s[i] == ch)
		{
			v.push_back(i);
		}
	}
	for(auto elem : v)
	{
		cout << elem + 1 << ' ';
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