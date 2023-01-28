#include<bits/stdc++.h>
using namespace std;
const int LOG_MAX = 100;
vector<vector<int> > succersors(vector<int>& graph){
	int n = graph.size();
	vector<vector<int> > succ(n, vector<int>(LOG_MAX));
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
pair<int, int> Floyd(int u, vector<vector<int> >& succ){
	int a = succ[u][0];
	int b = succ[u][1];
	while(a != b){
		a = succ[a][0];
		b = succ[b][1];
	}
	a = u;
	while(a != b){
		a = succ[a][0];
		b = succ[b][0];
	}
	int first = a;
	b = succ[first][0];
	int length = 1;
	while(b != first){
		b = succ[b][0];
		++length;
	}
	return {first, length};
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
	int f, l;
	tie(f, l) = Floyd(1, succ) ;
	cerr << f << ' ' << l << '\n';
}