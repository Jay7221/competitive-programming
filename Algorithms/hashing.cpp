#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Modulo
{
	public:
		int MOD = 1e9 + 7;
		Modulo()
		{
			MOD = 1e9 + 7;
		}
		Modulo(int M)
		{
			MOD = M;
		}
		void set(int M)
		{
			MOD = M;
		}
		int add(int a, int b)
		{
			ll x = a, y = b;
			return ((x + y) % MOD);
		}
		int sub(int a, int b)
		{
			ll x = a, y = b;
			return ((((x - y) % MOD) + MOD) % MOD);
		}
		int mult(int a, int b)
		{
			ll x = a, y = b;
			return ((x * y) % MOD);
		}
		int pow(int a, int p)
		{
			int ans = 1, res = a;
			while(p)
			{
				if(p & 1)
				{
					ans = mult(ans, res);
				}
				res = mult(res, res);
				p >>= 1;
			}
			return ans;
		}
		int getInverse(int a)
		{
			return 0;
		}
};
class SetHash
{
	public:
		Modulo M;
		int K = 199344;
		int H = 57;
		int curHash;
		SetHash()
		{
			curHash = 0;
		}
		SetHash(vector<int> &v)
		{
			curHash = 0;
			for(auto elem : v)
			{
				this -> insert(elem);
			}
		}
		SetHash(vector<int> v)
		{
			curHash = 0;
			for(auto elem : v)
			{
				this -> insert(elem);
			}
		}
		int hash(int x)
		{
			int ans = x;
			ans = M.add(x, K);
			ans = M.pow(ans, H);
			return ans;
		}
		void insert(int x)
		{
			curHash = M.add(curHash, hash(x));
		}
		bool cmp(SetHash &other)
		{
			return (curHash == other.curHash);
		}
};
class XorHash
{
	public:
		Modulo M;
		int K = 13430;
		int curHash;
		XorHash()
		{
			curHash = 0;
		}
		XorHash(vector<int> &v)
		{
			curHash = 0;
			for(auto elem : v)
			{
				this -> insert(elem);
			}
		}
		XorHash(vector<int> v)
		{
			curHash = 0;
			for(auto elem : v)
			{
				this -> insert(elem);
			}
		}
		int hash(int x)
		{
			return M.add(x, K);
		}
		void insert(int x)
		{
			curHash = (curHash ^ (this -> hash(x)));
		}
		bool cmp(XorHash &other)
		{
			return (this -> curHash == other.curHash);
		}

};

int main()
{
	XorHash s1({1, 2, 3, 4, 1, 2, 1, 2}), s2({4, 2, 3, 1});
	cerr << s1.cmp(s2) << '\n';
	return 0;
}
