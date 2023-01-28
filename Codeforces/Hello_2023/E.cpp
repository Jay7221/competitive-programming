#include<bits/stdc++.h>
using namespace std;
vector<int> in, out;
void answer(vector<bool> &v)
{
	cout << "! ";
	for(int elem : v)
	{
		cout << elem;
	}
	cout << endl;
}
int query(int i, vector<bool> &s)
{
	cout << "? " << (i + 1) << ' ';
	for(int elem : s)
	{
		cout << elem;
	}
	cout << endl;
	int ans;
	cin >> ans;
	return ans;
}
bool cmp(int a, int b)
{
	return (out[a] < out[b]);
}
void solve()
{
	int n;
	cin >> n;
	vector<bool> s(n, 1);
	in.assign(n, 0);
	out.assign(n, 0);
	vector<int> v;
	for(int i = 0; i < n; ++i)
	{
		v.push_back(i);
		s[i] = 0;
		int k = query(i, s);
		s[i] = 1;
		in[i] = n - 1 - k;
		out[i] = k;
	}
	s.assign(n, 0);
	sort(v.rbegin(), v.rend(), cmp);
	s[v[0]] = 1;
	for(int i = 1, j = 1; i < v.size(); ++i)
	{
		if(query(v[i], s) > 0)
		{
			for(int k = j; k <= i; ++k)
			{
				s[v[k]] = 1;
			}
		}
	}
	answer(s);
}

int main()
{
	solve();
	return 0;
}