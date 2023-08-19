#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Hash
{
	public:
		string s;
		ll MOD;
		vector<int> pre;
		vector<int> inv;
		vector<int> pow;
		int invOfBase;
		int base;
		int n;
		Hash(string s, int m)
		{
			this -> s = s;
			MOD = m;
			n = s.size();
			pre.resize(n + 1);
			inv.resize(n + 1);
			pow.resize(n + 1);
			for(int i = 1; i <= n; ++i)
			{
				pre[i] = s[i - 1] - 'a';
			}
			vector<int> tmp(30);
			tmp[1] = 1;
			for(int i = 2; i < 30; ++i)
			{
				int r = m % i;
				int q = m / i;
				tmp[i] = sub(m, mult(q, tmp[r]));
			}
			base = 26;
			invOfBase = tmp[base];
			inv[0] = 1;
			pow[0] = 1;
			for(int i = 1; i <= n; ++i)
			{
				inv[i] = mult(inv[i - 1], invOfBase);
				pow[i] = mult(pow[i - 1], base);
			}
			for(int i = 1; i <= n; ++i)
			{
				pre[i] = mult(pow[i], pre[i]);
				pre[i] =  add(pre[i], pre[i - 1]);
			}
		}
		int add(int a, int b)
		{
			ll ans = a;
			ans = (ans + b) % MOD;
			return ans;
		}
		int mult(int a, int b)
		{
			ll ans = a;
			ans = (ans * b) % MOD;
			return ans;
		}
		int sub(int a, int b)
		{
			ll ans = a;
			ans = ((ans - b) % MOD + MOD) % MOD;
			return ans;
		}
		int get(int l, int r)
		{
			int ans = sub(pre[r], pre[l - 1]);
			ans = mult(ans, inv[l]);
			return ans;
		}
};
void solve()
{
	int n, k;
	cin >> n >> k;
	string s, t;
	cin >> s >> t;
	int prime1 = 1e9 + 7, prime2 = 1e9 + 7;
	Hash hs1(s, prime1), ht1(t, prime1), hs2(s, prime2), ht2(t, prime2);
	map<tuple<int, int, int, int>, int> mp;
	int ans = 0;
	for(int i = 1; i + k - 1 <= n; ++i)
	{
		int l = i, m = i + k / 2 - 1, r = i + k - 1;
		int h1 = ht1.get(l, m);
		int h2 = ht1.get(m + 1, r);
		int h3 = ht2.get(l, m);
		int h4 = ht2.get(m + 1, r);
		mp[{h1, h2, h3, h4}] += 1;
	}
	for(int i = 1; i + k - 1 <= n; ++i)
	{
		int l = i, m = i + k / 2 - 1, r = i + k - 1;
		int h1 = hs1.get(l, m);
		int h2 = hs1.get(m + 1, r);
		int h3 = hs2.get(l, m);
		int h4 = hs2.get(m + 1, r);
		swap(h1, h2);
		swap(h3, h4);
		if(mp[{h1, h2, h3, h4}])
		{
			++ans;
		}
	}
	cout << ans << '\n';
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