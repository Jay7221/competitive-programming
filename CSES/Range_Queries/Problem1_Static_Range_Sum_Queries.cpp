#include<iostream>
using namespace std;
#define ll long long
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	ll pre[n + 2] = {0ll};
	for(int i = 1; i <= n; ++i)
	{
		cin >> pre[i];
		pre[i] += pre[i - 1];
	}
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		cout << (pre[b] - pre[a - 1]) << '\n';
	}
}