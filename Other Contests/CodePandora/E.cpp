#include<iostream>
using namespace std;
void solve()
{
	int r, g, b, n;
	cin >> r >> b >> g >> n;
	if((r < g) && (r < b))
	{
		g = max(0, n - g);
		b = max(0, n - b);
		cout << "BLUE " << b << " GREEN " << g << '\n';
	}
	else if((g < r) && (g < b))
	{
		r = max(0, n - r);
		b = max(0, n - b);
		cout << "BLUE " << b << " RED " << r << '\n';
	}
	else if((b < r) && (b < g))
	{
		r = max(0, n - r);
		g = max(0, n - g);
		cout << "GREEN " << g << " RED " << r << '\n';
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