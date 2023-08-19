#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n;
	ll c;
	cin >> n >> c;
	ll a[n + 1];
	int mn = c, mnInd = -1;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if(mn > a[i] + i)
		{
			mn = a[i] + i;
			mnInd = i;
		}
	}
	int ans = 0;
	multiset<int> m;
	for(int i = 1; i <= n; ++i)
	{
		m.insert(a[i] + min(i, n + 1 - i));
	}
	while((m.size() > 0) && (c >= (*m.begin())))
	{
		++ans;
		m.erase(m.begin());
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