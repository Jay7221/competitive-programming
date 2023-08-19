#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 2e5 + 7;
const int MOD = 998244353;
class Modulo
{
	public:
		int MAX = 2e5 + 7;
		vector<int> fact, inv, invFact;
		int mult(int a, int b)
		{
			ll aa = a, bb = b;
			return (aa * bb) % MOD;
		}
		int add(int a, int b)
		{
			ll aa = a, bb = b;
			return ((aa + bb) % MOD);
		}
		int sub(int a, int b)
		{
			ll aa = a, bb = b;
			return ((((aa - bb) % MOD) + MOD) % MOD);
		}
		int div(int a, int b)
		{
			cerr << a << ' ' << b << '\n';
			return mult(a, inv[b]);
		}
		int factorial(int a)
		{
			return fact[a];
		}
		int inv_factorial(int n)
		{
			return invFact[n];
		}
		Modulo()
		{
			fact.assign(MAX, 0);
			inv.assign(MAX, 0);
			invFact.assign(MAX, 0);
			inv[1] = 1;
			for(int i = 2; i < MAX; ++i)
			{
				int q = MOD / i;
				int r = MOD % i;
				inv[i] = mult(q, sub(MOD, inv[r]));
			}
			fact[0] = 1;
			invFact[0] = 1;
			for(int i = 1; i < MAX; ++i)
			{
				fact[i] = mult(fact[i - 1], i);
				invFact[i] = mult(invFact[i - 1], inv[i]);
			}
		}
};
class SegmentTree
{
	public:
		int n;
		vector<int> tree;
		int add(int a, int b)
		{
			ll aa = a, bb = b;
			return ((aa + bb) % MOD);
		}
		SegmentTree(int size)
		{
			n = size * 2;
			tree.assign(2 * n, 0);
		}
		void set(int ind, int val)
		{
			ind += n;
			tree[ind] = val;
			ind /= 2;
			while(ind > 0)
			{
				tree[ind] = add(tree[2 * ind], tree[2 * ind + 1]);
				ind /= 2;
			}
		}
		int query(int l, int r)
		{
			l += n, r += n;
			int ans = 0;
			while(l <= r)
			{
				if(l % 2 == 1)
				{
					ans = add(ans, tree[l]);
					++l;
				}
				if(r % 2 == 0)
				{
					ans = add(ans, tree[r]);
					--r;
				}
				l /= 2;
				r /= 2;
			}
			return ans;
		}
};

int compressIndex(vector<int> &s, vector<int> &t)
{
	vector<int> indexOf(MAX, -1);
	set<int> tmp_set;
	for(int elem : s)
	{
		tmp_set.insert(elem);
	}
	for(int elem : t)
	{
		tmp_set.insert(elem);
	}
	int cur = 0;
	for(int elem : tmp_set)
	{
		indexOf[elem] = cur++;
	}
	for(int &elem : s)
	{
		elem = indexOf[elem];
	}
	for(int &elem : t)
	{
		elem = indexOf[elem];
	}
	return cur;
}
void solve()
{
	Modulo M;
	int n, m;
	cin >> n >> m;
	vector<int> s(n), t(m);
	for(int i = 0; i < n; ++i)
	{
		cin >> s[i];
	}
	for(int i = 0; i < m; ++i)
	{
		cin >> t[i];
	}
	int sizeAlphabet = compressIndex(s, t);


	vector<int> freq(sizeAlphabet);
	for(int i = 0; i < n; ++i)
	{
		++freq[s[i]];
	}
	auto getContrib = [&](int f)
	{
		if(f <= 0)
		{
			return 0;
		}
		return M.mult(M.factorial(f), M.invFact[f - 1]);
	};
	SegmentTree tree(sizeAlphabet);
	for(int i = 0; i < sizeAlphabet; ++i)
	{
		tree.set(i, getContrib(freq[i]));
	}
	int curSum = n;
	int curMult = M.factorial(curSum);
	for(int i = 0; i < sizeAlphabet; ++i)
	{
		curMult = M.mult(curMult, M.invFact[freq[i]]);
	}
	int ans = 0;
	for(int i = 0; i < m; ++i)
	{
		if(i >= n)
		{
			ans = M.add(ans, 1);
			break;
		}
		curMult = M.mult(curMult, M.mult(M.factorial(curSum - 1), M.inv_factorial(curSum)));
		--curSum;
		ans = M.add(ans, M.mult(curMult, tree.query(0, t[i] - 1)));
		if(freq[t[i]] == 0)
		{
			break;
		}
		curMult = M.mult(curMult, M.factorial(freq[t[i]]));
		--freq[t[i]];
		curMult = M.mult(curMult, M.invFact[freq[t[i]]]);
		tree.set(t[i], getContrib(freq[t[i]]));
	}
	cout << ans << '\n';
}
int main(){
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