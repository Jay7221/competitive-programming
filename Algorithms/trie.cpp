#include<bits/stdc++.h>
using namespace std;
int ALPHABET_SIZE = 30;
class Trie
{
	class Node
	{
		public:
			vector<Node*> children;
			bool isEndWord;
			Node()
			{
				children.assign(ALPHABET_SIZE, NULL);
				isEndWord = false;
			}
	};
	public:
		Node *root;
		Trie()
		{
			root = new Node();
		}
		void insert(string s)
		{
			Node *cur = root;
			for(auto elem : s)
			{
				int ch = elem - 'a';
				if(cur -> children[ch] == NULL)
				{
					cur -> children[ch] = new Node();
				}
				cur = cur -> children[ch];
			}
			cur -> isEndWord = true;
		}
		bool search(string s)
		{
			Node *cur = root;
			for(auto elem : s)
			{
				int ch = elem - 'a';
				if(cur -> children[ch] == NULL)
				{
					return false;
				}
				cur = cur -> children[ch];
			}
			return (cur -> isEndWord);
		}
};
class BinaryTrie
{
	const static int ALPHABET_SIZE = 2;
	class Node
	{
		public:
			vector<Node*> children;
			bool isEndWord;
			Node()
			{
				children.assign(ALPHABET_SIZE, NULL);
				isEndWord = false;
			}
	};
	public:
		Node *root;
		BinaryTrie()
		{
			root = new Node();
		}
		void insert(int n)
		{
			Node *cur = root;
			for(int k = 31; k >= 0; --k)
			{
				int ch = ((n >> k) & 1);
				if(cur -> children[ch] == NULL)
				{
					cur -> children[ch] = new Node();
				}
				cur = cur -> children[ch];
			}
			cur -> isEndWord = true;
		}
		bool search(int n)
		{
			Node *cur = root;
			for(int k = 31; k >= 0; --k)
			{
				int ch = ((n >> k) & 1);
				if(cur -> children[ch] == NULL)
				{
					return false;
				}
				cur = cur -> children[ch];
			}
			return (cur -> isEndWord);
		}
		int maxXor(int n)
		{
			int ans = 0;
			Node *cur = root;
			for(int k = 31; k >= 0; --k)
			{
				int ch = ((n >> k) & 1);
				ch = (1 - ch);
				if(cur -> children[ch] != NULL)
				{
					cur = cur -> children[ch];
					ans += (1 << k);
				}
				else
				{
					cur = cur -> children[(1 - ch)];
				}
			}
			return ans;
		}
};
int main()
{
	BinaryTrie t;
	t.insert(4);
	t.insert(2);
	cerr << t.maxXor(4) << '\n';
	cerr << t.search(10) << '\n';
	return 0;
}
