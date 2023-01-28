#include<bits/stdc++.h>
using namespace std;
bool flag = 1;
int color(int n)
{
	// for root k = 1, and thus k % 2 == 1 => node is black
	// and k % 2 == 0 => node is red
	int k = 0;
	while((1 << k) <= n)
	{
		++k;
	}
	// function returns 0 if node is black and 1 if red
	return ((k % 2) == 0);
}
int solveRed(int x, int y)
{
	int ans = 0;
	if(x < y)
	{
		swap(x, y);
	}
	int colorx = color(x), colory = color(y);
	while(2 * y < x)
	{
		ans += colorx;
		colorx ^= 1;
		x /= 2;
	}
	while(x != y)
	{
		ans += colorx + colory;
		x /= 2, y /= 2;
		colorx ^= 1, colory ^= 1;
	}
	ans += colorx;
	return ans;
}
int solveBlack(int x, int y)
{
	int ans = 0;
	if(x < y)
	{
		swap(x, y);
	}
	int colorx = color(x), colory = color(y);
	colorx ^= 1, colory ^= 1;
	while(2 * y < x)
	{
		ans += colorx;
		colorx ^= 1;
		x /= 2;
	}
	while(x != y)
	{
		ans += colorx + colory;
		x /= 2, y /= 2;
		colorx ^= 1, colory ^= 1;
	}
	ans += colorx;
	return ans;
}
void solve()
{
	string s;
	cin >> s;
	if(s == "Qi")
	{
		flag ^= 1;
	}
	else if(s == "Qb")
	{
		int x, y;
		cin >> x >> y;
		if(flag)
		{
			cout << solveBlack(x, y) << '\n';
		}
		else
		{
			cout << solveRed(x, y) << '\n';
		}
	}
	else
	{
		int x, y;
		cin >> x >> y;
		if(flag)
		{
			cout << solveRed(x, y) << '\n';
		}
		else
		{
			cout << solveBlack(x, y) << '\n';
		}
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
