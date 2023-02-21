#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void debug(vector<int> &arr)
{
	for(int i = 1; i < arr.size(); ++i)
	{
		cerr << arr[i] << ' ';
	}
	cerr << '\n';
}

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<int> dp(n + 1), ans(n + 1), preMax(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		int numBooks;
		if(a[i] > i)
		{
			dp[i] = -INF;
			numBooks = n - (a[i] - 1);
		}
		else
		{
			dp[i] = 1 + preMax[i - a[i]];
			numBooks = dp[i] + (n - i);
		}
		if(numBooks >= 0)
		{
			ans[numBooks] = max(ans[numBooks], i);
		}
		preMax[i] = max(preMax[i - 1], dp[i]);
	}
	// debug(a);
	// debug(dp);
	// debug(preMax);
	for(int k = n; k > 0; --k)
	{
		ans[k - 1] = max(ans[k - 1], ans[k]);
	}
	int q;
	cin >> q;
	while(q--)
	{
		int k;
		cin >> k;
		cout << ans[k] << '\n';
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