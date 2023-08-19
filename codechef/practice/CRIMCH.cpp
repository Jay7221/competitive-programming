#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(int i = 1; i < a.size(); i++){cerr << i << " : "; for(auto k : a[i]){cerr << k << ' ' ;} cerr << '\n';} cerr << '\n';
bool bfs(int a, vector<vector<int> >& graph, vector<bool>& visited, vector<bool>& teams){
	queue<int> next;
	next.push(a);
	visited[a] = 1;
	bool cur_team = 0;
	teams[a] = cur_team;
	while(!next.empty()){
		cur_team ^= 1;
		queue<int> temp = next;
		while(!next.empty())	next.pop();
		while(!temp.empty()){
			int node = temp.front();
			temp.pop();
			for(auto neighbour : graph[node]){
				if(visited[neighbour]){
					if(teams[neighbour] == teams[node])
						return 0;
				}
				else{
					visited[neighbour] = 1;
					teams[neighbour] = cur_team;
					next.push(neighbour);
				}
			}
		}
	}
	return 1;
}
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > graph(n + 1);
	vector<bool> visited(n + 1, 1);
	vector<bool> teams(n + 1, 0); 		// initially all members are in team zero
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		visited[a] = visited[b] = 0;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	// debug(graph)
	for(int i = 1; i < n + 1; i++){
		if(!visited[i]){
			if(!bfs(i, graph, visited, teams)){
				cout << "NO" << '\n';
				return ;
			}
		}
	}
	cout << "YES" << '\n';
	return ;
}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}