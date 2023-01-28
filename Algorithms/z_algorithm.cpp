#include<bits/stdc++.h>
using namespace std;
class ZAlgorithm
{
	public:
		vector<int> p;
		int len, pat_len;
		void run(string &s)
		{
			len = s.size();
			int n = len;
			p.assign(n, 0);
			int l = 0, r = 0;
			for(int i = 1; i < n; ++i)
			{
				p[i] = max(0, min(r - i, p[i - l]));
				while(((i + p[i]) < n) && (s[i + p[i]] == s[p[i]]))
				{
					++p[i];
				}
				if(i + p[i] > r)
				{
					l =  i;
					r = i + p[i];
				}
			}
		}
		void build(string &data, string &pattern)
		{
			pat_len = pattern.size();
			string t = pattern + "$" + data;
			run(t);
		}
		int query(int index)
		{
			index = index + pat_len + 1;
			return p[index];
		}

};
int main()
{
	ZAlgorithm z;
	string s, p;
	cin >> s >> p;
	z.build(s, p);
	return 0;
}
