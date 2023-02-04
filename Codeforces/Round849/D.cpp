#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> freq(26);
	vector<bool> vis(26);
	int ans = 0;
	for(int i = 0; i < n; ++i)
	{
		int ch = s[i] - 'a';
		if(!vis[ch])
		{
			++ans;
			vis[ch] = true;
		}
		++freq[ch];
	}
	int pre = 0, suf = ans;
	vis.assign(26, false);

	for(int i = 0; i < n; ++i)
	{
		int ch = s[i] - 'a';
		--freq[ch];
		if(freq[ch] == 0)
		{
			--suf;
		}
		if(!vis[ch])
		{
			vis[ch] = true;
			++pre;
		}
		ans = max(ans, pre + suf);
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