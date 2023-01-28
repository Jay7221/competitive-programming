#include<iostream>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	int freq[101] = {0};
	for(int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		++freq[a];
	}
	bool flag = true;
	for(int i = 0; i < 101; ++i)
	{
		if(freq[i] % 2)
		{
			flag = false;
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