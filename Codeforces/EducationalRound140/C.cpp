#include<bits/stdc++.h>
using namespace std;
const int N = 101;
int n;
int condition[N][N], dp[N][N][2];
bool condition1[N][N], condition2[N][N], done[N][N];
bool vis[N][N];
const long long MOD = 998244353;
int add(int x, int y)
{
	long long sum = x;
	sum = (sum + y) % MOD;
	return sum;
}
int mult(int x, int y)
{
	long long prod = x;
	prod = (prod * y) % MOD;
	return prod;
}
bool check(int l, int r)
{
	return ((l >= 1) && (r <= n) && (l <= r));
}
void update(int l, int r)
{
	if(done[l][r] || (l == r) || (l + 1 == r))
	{
		return;
	}
	done[l][r] = true;
	update(l + 1, r);
	update(l, r - 1);
	condition1[l][r] |= (condition1[l][r - 1] & condition1[l + 1][r]);
}
void update1(int l, int r)
{
	if(!check(l, r))
	{
		return ;
	}
	if(condition1[l][r])
	{
		return ;
	}
	condition1[l][r] = true;
	update1(l + 1, r);
	update1(l, r - 1);
}
void update2(int l, int r)
{
	if(!check(l, r))
	{
		return ;
	}
	if(condition2[l][r])
	{
		return ;
	}
	condition2[l][r] = true;
	update2(l, r + 1);
	update2(l - 1, r);
}
void process(int l, int r)
{
	// assume that {l + 1, r} and {l, r - 1} are already processed
	// dp[l][r][0] = number of ways to fill the string from l + 1 to r, given that s[l] is fixed, with all letters same
	// dp[l][r][1] = number of ways to fill the string from l + 1 to r, given that s[l] is fixed, with atleast two distinct letters
	if(vis[l][r])
	{
		return;
	}
	vis[l][r] = true;
	if(l == r)
	{
		dp[l][r][0] = 1;
		dp[l][r][1] = 0;
	}
	else
	{
		process(l, r - 1);
		process(l + 1, r);
		if(l + 1 == r)
		{
			if(dp[l][l][0] == 1 && dp[r][r][0] == 1)
			{
				dp[l][r][0] = 1;
				dp[l][r][1] = 1;
			}
		}
		else
		{
			dp[l][r][0] = (dp[l][r - 1][0] & dp[l + 1][r][0]);
			dp[l][r][1] = mult(dp[l][r - 1][1], add(dp[r - 1][r][0], dp[r - 1][r][1]));
			dp[l][r][1] = add(dp[l][r][1], mult(dp[l][r - 1][0], dp[r - 1][r][1]));
		}
		// if(dp[l][r - 1][0] && dp[l + 1][r][0])
		// {
		// 	dp[l][r][0] = 1;
		// }
		// if(l == r + 1)
		// {
		// 	dp[l][r][1] = 2;
		// }
		// else
		// {
		// 	dp[l][r][1] = mult(dp[l][r - 1][1], add(dp[r - 1][r][0], dp[r - 1][r][1]));

		// 	if(dp[l][r - 1][0] && dp[r][r][0])
		// 	{
		// 		dp[l][r][1] = add(dp[l][r][1], 1);
		// 	}
		// }

	}

	if(condition1[l][r])
	{
		dp[l][r][1] = 0;
	}
	if(condition2[l][r])
	{
		dp[l][r][0] = 0;
	}
	// if(l + 2 == r)
	// {
	// 	cerr << l << ' ' << r << " : " << dp[l][r][0] << ' ' << dp[l][r][1] << '\n';
	// }
}
void solve()
{
	cin >> n;
	for(int l = 1; l <= n; ++l)
	{
		bool flag = true;
		for(int r = l; r <= n; ++r)
		{
			cin >> condition[l][r];
			if(condition[l][r] == 1)
			{
				update1(l, r);
			}
			if(condition[l][r] == 2)
			{
				update2(l, r);
			}
		}
	}
	update(1, n);
	condition1[1][9] = condition2[1][9] = 0;
	process(1, n);
	vector<pair<int, int>> v = {{9, 10}, {1, 9}, {10, 10}, {1, 10}, {14, 16}};

	for(auto [x, y] : v)
	{
		cerr << x << ' ' << y << " : " << dp[x][y][0] << ' ' << dp[x][y][1] << '\n';
		// cerr << condition1[x][y] << ' ' << condition2[x][y] << '\n';
	}
	cout << mult(add(dp[1][n][0], dp[1][n][1]), 2) << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	while(t--)
	{
		solve();
	}
	return 0;
}