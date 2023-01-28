#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
template<typename T>
void debug(T arr)
{
	for(auto elem : arr)
	{
		cerr << elem << ' ';
	}
	cerr << '\n';
}
template<typename T>
void debug2(T arr)
{
	for(auto elem : arr)
	{
		cerr << "(" << elem.first << ", " << elem.second << "), " << ' ';
	}
	cerr << '\n';
}
struct Trie
{
	Trie *child[2] = {NULL};
};
void insert(Trie *root, int x)
{
	for(int k = 31; k >= 0; --k)
	{
		int ch = ((x >> k) & 1);
		if(root -> child[ch] == NULL)
		{
			root -> child[ch] = new Trie;
		}
		root = root -> child[ch];
	}
}
int find_greatest(Trie *root, int x)
{
	int ans = 0;
	for(int k = 31; k >= 0; --k)
	{
		int ch = ((x >> k) & 1);
		ch ^= 1;
		ans ^= (1 << k);
		if(root -> child[ch] == NULL)
		{
			ch ^= 1;
			ans ^= (1 << k);
		}
		root = root -> child[ch];
	}
	return ans;
}

void solve()
{
	int n;
	cin >> n;
	int a[n + 2], pre[n + 2];
	for(int i = 0; i < n + 2; ++i)
	{
		a[i] = pre[i] = 0;
	}
	Trie *trie[n + 2];
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		pre[i] = a[i] ^ pre[i - 1];
	}
	pre[n + 1] = pre[n];
	int left[n + 2], right[n + 2];
	stack<int> st;
	for(int i = 1; i <= n; ++i)
	{
		while((st.size()) && (a[i] >= a[st.top()]))
		{
			st.pop();
		}
		if(st.size())
		{
			left[i] = st.top();
		}
		else
		{
			left[i] = 0;
		}
		st.push(i);
	}
	while(st.size())
	{
		st.pop();
	}
	for(int i = n; i > 0; --i)
	{
		while((st.size()) && (a[i] > a[st.top()]))
		{
			st.pop();
		}
		if(st.size())
		{
			right[i] = st.top();
		}
		else
		{
			right[i] = n + 1;
		}
		st.push(i);
	}

	for(int i = 1; i < n + 2; ++i)
	{
		trie[i] = new Trie;
		insert(trie[i], pre[i - 1]);
	}


	vector<pair<int, int>> v;
	for(int i = 1; i <= n; ++i)
	{
		v.push_back({a[i], i});
	}
	sort(v.begin(), v.end());

	int ans = 0;
	for(auto [aa, x] : v)
	{
		int l = left[x] + 1;
		int r = right[x] - 1;
		if(x - l < r - x)
		{
			for(int i = l; i <= x; ++i)
			{
				ans = max(ans, find_greatest(trie[x + 1], pre[i - 1] ^ a[x]));
			}
			for(int i = l; i <= x; ++i)
			{
				insert(trie[x + 1], pre[i - 1]);
			}
			delete trie[l];
			trie[l] = trie[x + 1];
		}
		else
		{
			for(int i = x; i <= r; ++i)
			{
				ans = max(ans, find_greatest(trie[l], pre[i] ^ a[x]));
			}
			for(int i = x; i <= r; ++i)
			{
				insert(trie[l], pre[i]);
			}
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