#include<iostream>
using namespace std;
void solve()
{
	int n, k, d;
	cin >> n >> k >> d;
	int cur = 0;
	bool flag = false;
	for(int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		if(a >= k)
		{
			++cur;
		}
		else
		{
			cur = 0;
		}
		if(cur >= d)
		{
			flag = true;
		}
	}
	if(flag)
	{
		cout << "Happy\n";
	}
	else
	{
		cout << "Sad\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}