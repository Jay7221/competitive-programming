#include<bits/stdc++.h>
using namespace std;
int add(int a, int b)
{
	return ((a + b) % 9);
}
int sub(int a, int b)
{
	return ((a - b + 9) % 9);
}
template<typename T>
void debug(T &arr)
{
	for(auto elem : arr)
	{
		cerr << elem << ' ';
	}
	cerr << '\n';
}
void solve()
{
	string s;
	int n, w, m;
	cin >> s;
	cin >> w >> m;
	n = s.size();
	int dp[9][9][2];
	bool vis[9][9], ok[9][9];
	for(int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < 9; ++j)
		{
			for(int k = 0; k < 2; ++k)
			{
				dp[i][j][k] = n + 1;
			}
			vis[i][j] = false;
			ok[i][j] = false;
		}
	}
	vector<int> pre(n);
	for(int i = 0; i < n; ++i)
	{
		pre[i] = s[i] - '0';
		if(i > 0)
		{
			pre[i] += pre[i - 1];
		}
	}


	vector<vector<int>> indices(9);
	int cur = 0;
	for(int i = 0; i < w; ++i)
	{
		cur = add(cur, s[i] - '0');
	}
	indices[cur].push_back(0);
	for(int i = w; i < n; ++i)
	{
		cur = add(cur, s[i] - '0');
		cur = sub(cur, s[i - w] - '0');
		indices[cur].push_back(i - w + 1);
	}
	// for(int i = 0; i < 9; ++i)
	// {
	// 	cerr << i << " : ";
	// 	debug(indices[i]);
	// }
	


	auto sum = [&](int l, int r)
	{
		int ans = pre[r];
		if(l > 0)
		{
			ans -= pre[l - 1];
		}
		ans %= 9;
		return ans;
	};
	auto calc = [&](int s, int k)
	{
		if(vis[s][k])
		{
			return dp[s][k];
		}
		vis[s][k] = true;
		s %= 9;
		k %= 9;
		bool flag = true;

		for(int i = 0; (i < 9) && flag; ++i)
		{
			for(int j = 0; (j < 9) && flag; ++j)
			{
				if((((s * i + j) % 9) == k))
				{
					if(i == j)
					{
						if(indices[i].size() < 2)
						{
							continue;
						}
						int l1 = *min_element(indices[i].begin(), indices[i].end());
						int l2 = n;
						for(auto elem : indices[i])
						{
							if((elem != l1) && (elem < l2))
							{
								l2 = elem;
							}
						}
						if((dp[s][k][0] > l1) || (dp[s][k][0] == l1 && dp[s][k][1] < l2)){
							dp[s][k][0] = l1;
							dp[s][k][1] = l2;
						}
					}
					else
					{
						if(indices[i].size() && indices[j].size())
						{
							int l1 = *min_element(indices[i].begin(), indices[i].end());
							int l2 = *min_element(indices[j].begin(), indices[j].end());
							if((dp[s][k][0] > l1) || (dp[s][k][0] == l1 && dp[s][k][1] < l2)){
								dp[s][k][0] = l1;
								dp[s][k][1] = l2;
							}
						}
					}
				}
			}
		}
		return dp[s][k];
	};
	while(m--)
	{
		int l, r, k;
		cin >> l >> r >> k;
		--l, --r;
		int a = sum(l, r);
		int l1, l2;
		calc(a, k);
		l1 = dp[a][k][0], l2 = dp[a][k][1];
		++l1, ++l2;
		if(l1 > n || l2 > n)
		{
			l1 = l2 = -1;
		}
		cout << l1 << ' ' << l2 << '\n';
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