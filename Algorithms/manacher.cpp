#include<bits/stdc++.h>
using namespace std;
class manacher
{
	public:
		vector<int> p;
		int len;
		void run_manacher(string &t)
		{
			len = t.size();
			int n = len;
			p.assign(n, 1);
			int l = -1, r = 0;
			for(int i = 0; i < n; ++i)
			{
				p[i] = max(p[i], min(r - i, p[r + l - i]));
				while((i + p[i] < n) && (i - p[i] >= 0) && (t[i + p[i]] == t[i - p[i]]))
				{
					++p[i];
				}
				if(i + p[i] > r)
				{
					l = i - p[i];
					r = i + p[i];
				}
			}

		}
		void build(string &s)
		{
			string t;
			for(auto elem : s)
			{
				t += '#';
				t += elem;
			}
			t += "#";
			run_manacher(t);
		}
		int get_longest(int index, bool is_odd)
		{
			// Gives the longest palindrome with centre at index "index"
			// Note that odd centre means that palindrome has odd length
			// While even centre means that palindrome has even length
			index = 2 * index + (!is_odd) + 1;
			return p[index] - 1;
		}
		int is_palindrome(int l, int r)
		{
			if((r - l + 1) > get_longest((r + l) / 2, l % 2 == r % 2))
			{
				return false;
			}
			return true;
		}
};
int main()
{
	string s;
	cin >> s;
	manacher M;
	M.build(s);
	int l, r;
	l = 0, r = 0;
	while(l != -1)
	{
		cin >> l >> r;
		cerr << M.is_palindrome(l, r) << '\n';
	}
	return 0;
}
