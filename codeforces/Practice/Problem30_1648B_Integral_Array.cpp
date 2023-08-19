#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
void solve()
{
	int n, c;
	cin >> n >> c;
	vector<int> a(n);
	vector<int> near(c + 7, INF);
	// near[k] = minimum number x, such that k + x is present in a
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		near[a[i]] = 0;
	}
	for(int i = c; i >= 0; --i)
	{
		near[i] = min(near[i], near[i + 1] + 1);
	}
	auto isInA = [&](int n)
	{
		return (near[n] == 0);
	};
	for(int k = 1; k <= c; ++k)
	{
		if(isInA(k))
		{
			continue;
		}
		for(int p = 1; k * p <= c; ++p)
		{
			if(!isInA(p))
			{
				continue;
			}
			if(near[k * p] < p)
			{
				cout << "No\n";
				return ;
			}
		}
	}
	cout << "Yes\n";
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