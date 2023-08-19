#include<iostream>
using namespace std;
#define ll long long
const int logmax = 30;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	ll a[n];
	ll pre[n][logmax], suf[n][logmax];
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		pre[i][0] = suf[i][0] = a[i];
	}
	for(int k = 1; k < logmax; ++k)
	{
		for(int i = 0; i < n; ++i)
		{
			pre[i][k] = min(pre[i][k - 1], pre[max(0, i - (1 << (k - 1)))][k - 1]);
			suf[i][k] = min(suf[i][k - 1], suf[min(n - 1, i + (1 << (k - 1)))][k - 1]);
		}
	}
	auto query = [&](int l, int r)
	{
		int sz = r - l + 1;
		int cur = 0;
		while((1 << (cur + 1)) <= sz)
		{
			++cur;
		}
		return min(pre[r][cur], suf[l][cur]);
	};
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		--a, --b;
		cout << query(a, b) << '\n';
	}
	return 0;
}