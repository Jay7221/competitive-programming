#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
int n, m;
const int MAX_M = 11;
class Node
{
	public:
		Node *child[MAX_M];
};
class Trie
{
	public:
		Node *root;
		Trie()
		{
			root = new Node();
		}
		void insert(vector<int> a)
		{
			Node *cur = root;
			for(int i = 0; i < m; ++i)
			{
				if(cur -> child[a[i]] == NULL)
				{
					cur -> child[a[i]] = new Node();
				}
				cur = cur -> child[a[i]];
			}
		}
		int getMaxPre(vector<int> a)
		{
			Node *cur = root;
			int ans = 0;
			for(int i = 0; i < m; ++i)
			{
				if(cur -> child[a[i]] == NULL)
				{
					return ans;
				}
				++ans;
				cur = cur -> child[a[i]];
			}
			return ans;
		}
};
vector<int> getIndex(vector<int> a)
{
	vector<int> index(m);
	vector<pair<int, int>> v;
	for(int i = 0; i < m; ++i)
	{
		index[a[i]] = i;
	}
	return index;
}
void solve()
{
	cin >> n >> m;
	a.assign(n, vector<int>(m));
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
			--a[i][j];
		}
	}
	Trie tr;
	for(int i = 0; i < n; ++i)
	{
		tr.insert(getIndex(a[i]));
	}
	for(int i = 0; i < n; ++i)
	{

		cout << tr.getMaxPre(a[i]) << ' ';
	}
	cout << '\n';
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