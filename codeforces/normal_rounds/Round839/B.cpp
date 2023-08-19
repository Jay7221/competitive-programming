#include<iostream>
using namespace std;
void solve()
{
	int mn = 101, mx = -1;
	int mni, mxi;
	for(int i = 0; i < 4; ++i)
	{
		int a;
		cin >> a;
		if(a > mx)
		{
			mx = a;
			mxi = i;
		}
		if(a < mn)
		{
			mn = a;
			mni = i;
		}
	}
	if(mni > mxi)
	{
		swap(mni, mxi);
	}
	if((mni == 0 && mxi == 3) || (mni == 1 && mxi == 2))
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