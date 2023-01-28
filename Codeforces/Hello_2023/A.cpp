#include<iostream>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0; i < n - 1; ++i)
	{
		if(s[i] == 'L' && s[i + 1] == 'R')
		{
			cout << (i + 1) << '\n';
			return ;
		}
		if(s[i] == 'R' && s[i + 1] == 'L')
		{
			cout << 0 << '\n';
			return ;
		}
	}
	cout << -1 << '\n';

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