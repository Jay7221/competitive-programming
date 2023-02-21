#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> freq(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		int a;
		cin >> a;
		freq[i] = (freq[i - 1] + (a == 2));
	}
	int k = -1;
	for(int i = 1; i < n; ++i)
	{
		if(2 * freq[i] == freq[n])
		{
			k = i;
			break;
		}
	}
	cout << k << '\n';
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