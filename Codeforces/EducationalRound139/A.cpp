#include<iostream>
using namespace std;
const int MAX = 1e6 + 7;
int dp[MAX];
void pre()
{
	for(int i = 1; i < 10; ++i)
	{
		for(int j = i; j < MAX; j *= 10)
		{
			dp[j] = 1;
		}
	}
	for(int i = 1; i < MAX; ++i)
	{
		dp[i] += dp[i - 1];
	}
}
void solve()
{
	int n;
	cin >> n;
	cout << dp[n] << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pre();
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}