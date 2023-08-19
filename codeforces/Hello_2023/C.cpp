#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	--m;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	ll sum;
	int ans = 0;

	
	sum = 0;
	multiset<ll> st;
	for(int i = m + 1; i < n; ++i)
	{
		st.insert(a[i]);
		sum += a[i];
		while(sum < 0)
		{
			ll f = *st.begin();
			st.erase(st.begin());
			++ans;
			sum -= 2 * f;
		}
	}






	sum = 0;
	st.clear();
	for(int k = m - 1; k >= 0; --k)
	{
		sum += a[k + 1];
		st.insert(a[k + 1]);
		while(sum > 0)
		{
			++ans;
			ll f = *(--st.end());
			st.erase(--st.end());
			sum -= 2 * f;
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