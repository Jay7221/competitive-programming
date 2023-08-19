#include<iostream>
using namespace std;

string pi = "314159265358979323846264338327950288419716939937510";

int getFirstDiff(string x)
{
	int ans = 0;
	while(ans < x.size())
	{
		if(x[ans] != pi[ans])
		{
			return ans;
		}
		++ans;
	}
	return ans;
}

void solve()
{
	string s;
	cin >> s;
	cout << getFirstDiff(s) << '\n';
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