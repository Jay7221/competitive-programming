#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> w(n);
	map<int, int> mp;
	int cur = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> w[i];
		cur += w[i];
		mp[cur] = i + 1;
	}
	reverse(w.begin(), w.end());
	int ans = 0;
	cur = 0;
	for(int i = 0; i < n; ++i)
	{
		cur += w[i];
		if((mp.find(cur) != mp.end()) && (mp[cur] + i + 1 <= n))
		{
			ans = max(ans, i + 1 + mp[cur]);
		}
	}
	cout << ans << '\n';
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