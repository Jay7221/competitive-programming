#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	int mx = (n + k - 1) / k;
	int mxCount = n % k;
	if(mxCount == 0)
	{
		mxCount += k;
	}
	bool flag = true;
	vector<int> a(m);
	for(int i = 0; i < m; ++i)
	{
		cin >> a[i];
	}
	for(auto elem : a)
	{
		if(elem > mx)
		{
			flag = false;
			break;
		}
		if(elem == mx)
		{
			if(mxCount == 0)
			{
				flag = false;
				break;
			}
			--mxCount;
		}
	}
	if(flag)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
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