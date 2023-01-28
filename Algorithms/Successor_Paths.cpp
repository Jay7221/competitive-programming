#include<bits/stdc++.h>
using namespace std;
const int LOG_MAX = 100;
vector<vector<int> > succersors(vector<int>& graph){
	// graph -> represents a successor graph
	int n = graph.size();
	int N = ceil(log2(n));
	vector<vector<int> > succ(n, vector<int>(LOG_MAX));
	// succ[u][i] -> gives the 2^i th successor of the node u
	for(int i = 1; i < n; ++i){
		succ[i][0] = graph[i];
	}
	for(int k = 1; k < LOG_MAX; ++k){
		for(int i = 1; i < n; ++i){
			succ[i][k] = succ[ succ[i][k - 1] ][k - 1];
		}
	}
	return succ;
}
int main(){
	int n, m;
	cin >> n >> m;
	vector<int> graph(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		graph[u] = v;
	}
	vector<vector<int> > succ = succersors(graph);
	auto get_succ = [&](int u, int k){
		int ans = u;
		for(int i = 0; (1 << i) <= n; ++i){
			if((1 << i) & k){
				ans = succ[ans][i];
			}
		}
		return ans;
	};
	cerr << get_succ(4, 6) << '\n';
}