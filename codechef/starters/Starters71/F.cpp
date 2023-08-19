#include<bits/stdc++.h>
using namespace std;
vector<int> a;
#define ll long long
int n;
bool check(int l, int r)
{
	if((l < 0) || (r > n - 1) || (l > r))
	{
		return false;
	}
	map<int, int> freq;
	int mx = 0;
	int mode;
	for(int i = l; i <= r; ++i)
	{
		++freq[a[i]];
		if(freq[a[i]] > mx)
		{
			mx = freq[a[i]];
			mode = a[i];
		}
	}
	for(int i = l; i <= r; ++i)
	{
		if((a[i] != mode) && (freq[a[i]] >= mx))
		{
			return false;
		}
	}
	return true;
}
void solve()
{
	cin >> n;
	a.assign(n, 0);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int ans = 0;
	for(int k = 1; k <= 100; ++k)
	{
		for(int i = 0; i < n; ++i)
		{
			if(check(i, i + k - 1))
			{
				++ans;
			}
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