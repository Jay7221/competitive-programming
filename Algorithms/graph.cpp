#include<bits/stdc++.h>
using namespace std;
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
void debug_pi(T arr)
{
	for(auto elem : arr)
	{
		cerr << "(" <<  elem.first << ' ' << elem.second << "), " << ' ' ;
	}
	cerr << '\n';
}
template<typename T>
void debug_graph(T graph)
{
	for(int i = 0; i < graph.size(); ++i)
	{
		cerr << i << " : ";
		debug(graph[i]);
	}
	cerr << "------\n";
}
class Graph
{
	public:
		vector<pair<int, int>> edges;
		vector<vector<int>> graph, graph_rev;
		vector<int> topological_order;
		vector<bool> vis;
		int n, m;
		Graph()
		{
			n = 0;
			m = 0;
		}
		Graph(vector<pair<int, int>> edges, int n)
		{
			this -> n = n;
			this -> edges = edges;
			graph.assign(n, vector<int>());
			graph_rev.assign(n, vector<int>());
			for(auto [u, v] : edges)
			{
				graph[u].push_back(v);
				graph_rev[v].push_back(u);
			}
		}
		vector<vector<int>> build_graph(vector<pair<int, int>> &edges, int n)
		{
			vector<vector<int>> graph(n);
			for(auto [u, v] : edges)
			{
				graph[u].push_back(v);
			}
			return graph;
		}
		vector<vector<int>> build_graph_rev(vector<pair<int, int>> &edges, int n)
		{
			vector<vector<int>> graph(n);
			for(auto [u, v] : edges)
			{
				graph[v].push_back(u);
			}
			return graph;
		}
		void dfs_topological(int u)
		{
			vis[u] = true;
			for(auto v : graph[u])
			{
				if(!vis[v])
				{
					dfs_topological(v);
				}
			}
			topological_order.push_back(u);
		}
		void topological_sort()
		{
			vis.assign(n, false);
			topological_order.clear();
			for(int i = 0; i < n; ++i)
			{
				if(!vis[i])
				{
					dfs_topological(i);
				}
			}
			reverse(topological_order.begin(), topological_order.end());
		}


		void dfs_component(int u, vector<int> &component)
		{
			vis[u] = true;
			component.push_back(u);
			for(auto v : graph_rev[u])
			{
				if(!vis[v])
				{
					dfs_component(v, component);
				}
			}
		}
		vector<int> get_roots()
		{
			vector<int> root(n);
			int cur_root = 0;
		
			vis.assign(n, false);
			topological_sort();
		
			vis.assign(n, false);
			for(auto u : topological_order)
			{
				if(!vis[u])
				{
					vector<int> component;
					dfs_component(u, component);
					for(auto v : component)
					{
						root[v] = cur_root;
					}
					++cur_root;
				}
			}
			return root;
		}
		vector<vector<int>> get_components()
		{
			vector<int> root = get_roots();
			int n = *max_element(root.begin(), root.end()) + 1;
			vector<vector<int>> components(n);
			for(int i = 0; i < (this -> n); ++i)
			{
				components[root[i]].push_back(i);
			}
			return components;
		}
		void condense()
		{
			vector<int> root = get_roots();
			set<pair<int, int>> new_edges;
			for(auto [u, v] : edges)
			{
				u = root[u];
				v = root[v];
				if(u != v)
				{
					new_edges.insert({u, v});
				}
			}
			this -> edges.clear();
			for(auto [u, v] : new_edges)
			{
				this -> edges.push_back({u, v});
			}
			this -> n = *max_element(root.begin(), root.end()) + 1;
			this -> graph = build_graph(this -> edges, this -> n);
			this -> graph_rev = build_graph_rev(this -> edges, this -> n);
		}
};
int main()
{
	vector<pair<int, int>> edges = {
		{0, 1},
		{1, 2},
		{2, 3},
		{3, 2}
	};
	Graph g(edges, 4);
	debug_graph(g.get_components());
	g.condense();
	debug(g.get_roots());
	return 0;
}
