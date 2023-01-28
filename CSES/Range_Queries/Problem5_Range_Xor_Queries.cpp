#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1), pre(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		pre[i] = (pre[i - 1] ^ a[i]);
	}
	auto query = [&](int l, int r)
	{
		return (pre[r] ^ pre[l - 1]);
	};
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		cout << query(a, b) << '\n';
	}
	return 0;
}