#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n, k;
	cin >> n >> k;
	priority_queue<int> q;
	for(int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		q.push(x);
	}
	ll ans = 0;
	int cur = n;
	for(int i = 0; i < k; ++i)
	{
		bool flag = true;
		while(flag)
		{
			int u = q.top();
			q.pop();
			if(u >= cur)
			{
				q.push(u % cur);
			}
			else
			{
				ans += u;
				flag = false;
			}
		}
		--cur;
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
