#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	map<string, int> freq;
	string r = "Red", g = "Green", b = "Blue";
	for(int i = 0; i < n; ++i)
	{
		int c;
		cin >> c;
		if(c == 1)
		{
			++freq[r];
		}
		else if(c == 2)
		{
			++freq[g];
		}
		else
		{
			++freq[b];
		}
	}
	if(freq[b] >= freq[r] && freq[b] >= freq[g])
	{
		cout << b << '\n';
	}
	else if(freq[g] >= freq[r] && freq[g] >= freq[b])
	{
		cout << g << '\n';
	}
	else
	{
		cout << r << '\n';
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