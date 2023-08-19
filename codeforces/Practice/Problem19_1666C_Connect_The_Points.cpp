#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e12 + 7;
void solve()
{
	vector<ll> x(3), y(3);
	for(int i = 0; i < 3; ++i)
	{
		cin >> x[i] >> y[i];
	}
	int mxX = *max_element(x.begin(), x.end());
	int mnX = *min_element(x.begin(), x.end());
	int mxY = *max_element(y.begin(), y.end());
	int mnY = *min_element(y.begin(), y.end());
	ll mn = INF;
	vector<vector<ll>> gAns;
	auto eval = [&](vector<vector<ll>> v)
	{
		ll ans = 0;
		for(auto seg : v)
		{
			ll x1 = seg[0], y1 = seg[1], x2 = seg[2], y2 = seg[3];
			ans += abs(x1 - x2) + abs(y1 - y2);
		}
		return ans;
	};
	auto calc = [&](int i)
	{
		ll xx = x[i], yy = y[i];
		vector<vector<ll>> ans;
		ll tmp = 0;
		ans.push_back({xx, mnY, xx, mxY});
		for(int i = 0; i < 3; ++i)
		{
			ans.push_back({x[i], y[i], xx, y[i]});
		}
		if(eval(ans) < mn)
		{
			mn = eval(ans);
			gAns = ans;
		}
	};
	for(int i = 0; i < 3; ++i)
	{
		calc(i);
	}
	cout << gAns.size() << '\n';
	for(auto seg : gAns)
	{
		for(int i = 0; i < 4; ++i)
		{
			cout << seg[i] << ' ';
		}
		cout << '\n';
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