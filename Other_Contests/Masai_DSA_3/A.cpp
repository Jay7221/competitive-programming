#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	int circle = 0, triangle = 0, square = 0, unknown = 0;
	for(int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		if(s == "Square")
		{
			++square;
		}
		else if(s == "Circle")
		{
			++circle;
		}
		else if(s == "Triangle")
		{
			++triangle;
		}
		else
		{
			++unknown;
		}
	}
	cout << "Square " << square << ' ' << "Circle " << circle << ' ' << "Triangle " << triangle << ' ' << "Unknown " << unknown << endl;
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