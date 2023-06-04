#include<iostream>
using namespace std;
void solve()
{
	int m;
	cin >> m;
	bool dp[2][m];
	for(int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			char ch;
			cin >> ch;
			dp[i][j] = (ch == 'B');
		}
	}
	for(int j = 1; j < m; ++j)
	{
		bool a = dp[0][j], b = dp[1][j];
		bool pa = dp[0][j - 1], pb = dp[1][j - 1];
		
		dp[0][j] &= (pa | b);
		dp[1][j] &= (pb | a);

		dp[0][j] &= !(b & (!pb));
		dp[1][j] &= !(a & (!pa));
	}
	// for(int i = 0; i < 2; ++i)
	// {
	// 	for(int j = 0; j < m; ++j)
	// 	{
	// 		cerr << dp[i][j] << ' ' ;
	// 	}
	// 	cerr << '\n';
	// }
	if(dp[0][m - 1] | dp[1][m - 1])
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