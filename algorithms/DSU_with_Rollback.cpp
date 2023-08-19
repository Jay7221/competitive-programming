#include<bits/stdc++.h>
using namespace std;
class DSURollback
{
	public:
		int n;
		int numberComponents, curState = 0;
		vector<int> par, rank;
		stack<pair<int, int>> moves;
		DSURollback(int n)
		{
			this -> n = n;
			this -> numberComponents = n;
			par.assign(n, 0);
			rank.assign(n, 1);
			for(int i = 0; i < n; ++i)
			{
				par[i] = i;
			}
		}
		int size()
		{
			return n;
		}
		int number_components()
		{
			return numberComponents;
		}
		int get_parent(int u)
		{
			if(u == par[u])
			{
				return u;
			}
			return get_parent(par[u]);
		}
		void merge(int u, int v)
		{
			u = get_parent(u);
			v = get_parent(v);
			if(u != v)
			{
				if(rank[u] < rank[v])
				{
					swap(u, v);
				}

				rank[u] += rank[v];
				par[v] = u;
				--numberComponents;
				++curState;
				moves.push({u, v});
			}
		}
		void rollback(int prevState)
		{
			while(curState > prevState)
			{
				int u, v;
				tie(u, v) = moves.top();
				moves.pop();
				rank[u] -= rank[v];
				par[v] = v;
				--curState;
				++numberComponents;
			}
		}
};
int main()
{
	return 0;
}
