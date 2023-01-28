#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n), wins(n), v;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		wins[i] = i + 1;
	}
	v = a;
	sort(v.begin(), v.end());
	int ans = n + 1, ind = -1, cur = 0;
	int mx = 0;
	for(int i = 0; i < n; ++i)
	{
		if(v[i] + cur <= m)
		{
			mx = v[i];
			cur += v[i];
			--ans;
			++ind;
		}
	}
	int i = ind;
	if(ind > -1)
	{
		if(a[i] == mx)
		{
			--ans;
		}
		else if(a[i] > mx)
		{
			if(cur + a[i] - mx <= m)
			{
				--ans;
			}
		}
	}
	ans = max(1, ans);
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