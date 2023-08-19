#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int a[3];
	for(int i = 0; i < 3; ++i)
	{
		cin >> a[i];
	}
	sort(a, a + 3);
	if(a[2] < a[0] + a[1])
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
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