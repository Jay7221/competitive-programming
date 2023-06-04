#include<iostream>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int vis[26][26];
	bool flag = false;
	for(int i = 0; i < 26; ++i)
	{
		for(int j = 0; j < 26; ++j){
			vis[i][j] = 0;
		}
	}
	for(int i = 1; i + 1 < n; ++i)
	{
		if(vis[s[i] - 'a'][s[i + 1] - 'a'])
		{
			flag = true;
		}
		vis[s[i - 1] - 'a'][s[i] - 'a'] = 1;
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