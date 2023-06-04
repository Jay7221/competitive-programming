#include<bits/stdc++.h>
using namespace std;

int query(int x)
{
	cout << "- " << x << endl;
	int n;
	cin >> n;
	return n;
}

void answer(int x)
{
	cout << "! " << x << endl;
}

int generate(int cnt)
{
	int ans = 0;
	for(int i = 0; i < cnt; ++i)
	{
		ans |= (1 << i);
	}
	return ans;
}

void solve()
{
	int n, cnt;
	n = 0;
	cin >> cnt;
	int buf = 0;

	for(int i = 0; (i < 30) && (cnt > buf); ++i)
	{
		int k = (1 << i);
		int q = query(k);
		n += k;
		if(q >= cnt)
		{
			++buf;
			n += k;
		}
		cnt = q;
	}
	answer(n);
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