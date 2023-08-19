#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<ll> cur_sum(n + 1), cur_contrib(n + 1);
	vector<ll> ans(m + 1);

	for(int i = 1; i <= m; ++i)
	{
		int p, t;
		cin >> p >> t;
		
		ans[i] = ans[i - 1] - cur_contrib[p];

		cur_sum[p] += t;
		cur_contrib[p] += cur_sum[p];
		
		ans[i] += cur_contrib[p];
	}

	for(int i = 1; i <= m; ++i)
	{
		cout << ans[i] << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	t = 1;
	while(t--)
	{
		solve();
	}
	return 0;
}