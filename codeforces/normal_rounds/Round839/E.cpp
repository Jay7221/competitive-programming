#include<iostream>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	int first = 0, second = 0, common = 0;
	for(int i = 1, j = n; i <= n; ++i, --j)
	{
		int p;
		cin >> p;
		if((p == i) && (p != j))
		{
			++second;
		}
		else if((p != i) && (p == j))
		{
			++first;
		}
		else if((p != i) && (p != j))
		{
			++common;
		}
	}
	if(first + common <= second)
	{
		cout << "First\n";
	}
	else if(second + common < first)
	{
		cout << "Second\n";
	}
	else
	{
		cout << "Tie\n";
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