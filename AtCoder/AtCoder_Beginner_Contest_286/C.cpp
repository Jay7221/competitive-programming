#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n;
	cin >> n;
	ll a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	auto get_cost = [&]()
	{
		int i = 0, j = n - 1;
		ll ans = 0;
		while(i < j)
		{
			ans += b * (s[i] != s[j]);
			++i, --j;
		}
		return ans;
	};
	ll ans = get_cost();
	ll cur = 0;
	for(int i = 0; i < n; ++i)
	{
		char ch = s[0];
		s.erase(s.begin());
		cur += a;
		s.push_back(ch);
		ans = min(ans, cur + get_cost());
	}
	cout << ans << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}