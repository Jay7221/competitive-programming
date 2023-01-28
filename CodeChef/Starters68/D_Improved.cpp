#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> freq;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		++freq[a[i]];
	}
	sort(a.begin(), a.end());
	int limit = n / 2 + n % 2;
	bool flag = false;
	int mx;
	for(int i = 0; i < n; ++i)
	{
		if(freq[a[i]] > limit)
		{
			cout << -1 << '\n';
			return ;
		}
		if(freq[a[i]] == limit)
		{
			flag = true;
			mx = a[i];
		}
	}
	vector<int> ans(n);
	if(flag)
	{
		for(int i = 0; i < n; i += 2)
		{
			ans[i] = mx;
		}
		for(int i = 1, j = 0; j < n; ++j, i += 2)
		{
			while(a[j] == mx)
				++j;
			ans[i] = a[j];
		}
	}
	else
	{
		for(int i = 1, j = 0; j < n / 2; ++j, i += 2)
		{
			ans[i] = a[j];
		}
		for(int i = 0, j = n / 2; j < n; ++j, i += 2)
		{
			ans[i] = a[j];
		}
	}
	for(auto elem : ans)
	{
		cout << elem << ' ';
	}
	cout << '\n';
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