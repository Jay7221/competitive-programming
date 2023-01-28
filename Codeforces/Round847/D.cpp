#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = 0;
	map<int, int> freq;
	for(int i = 0; i < n; ++i)
	{
		++freq[a[i]];
		++ans;
		if((freq.find(a[i] - 1) != freq.end()) && (freq[a[i] - 1] > 0))
		{
			--freq[a[i] - 1];
			--ans;
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