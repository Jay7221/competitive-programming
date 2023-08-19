#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool check(string &a, string &b)
{
	vector<int> freq(26), a_freq(26), b_freq(26);
	for(char elem : a)
	{
		++freq[elem - 'a'];
		++a_freq[elem - 'a'];
	}
	for(char elem : b)
	{
		++freq[elem - 'a'];
		++b_freq[elem - 'a'];
	}
	bool flag = false;
	for(int i = 0; i < 26; ++i)
	{
		if(freq[i] % 2 == 1)
		{
			if(flag)
			{
				return false;
			}
			flag = true;
		}
	}
	for(int i = 0; i < 26; ++i)
	{
		if(a_freq[i] < b_freq[i])
		{
			return false;
		}
	}
	return true;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	if(a.size() < b.size())
	{
		swap(a, b);
	}
	if(check(a, b))
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
	cin >> t;
	while(t--)
	{
		solve();
	}

	return 0;
}
