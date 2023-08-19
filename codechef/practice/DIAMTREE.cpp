#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int dfs(int a, vector<vector<int> >& tree, int& dist){
	queue<int> next;
	next.push(a);
	vector<bool> visited(n + 1, 0);
	visited[a] = 1;
	int cur_dist = 0;
	int farthest = a;
	while(!next.empty()){
		if(cur_dist > dist){
			dist = cur_dist;
			farthest = next.front();
		}
		cur_dist++;
		queue<int> temp = next;
		while(!next.empty())	next.pop();
		while(!temp.empty()){
			int cur = temp.front();
			temp.pop();
			for(auto child : tree[cur]){
				if(!visited[child]){
					visited[child] = 1;
					next.push(child);
				}
			}
		}
	}
	return farthest;
}
void solve(){
	// int n;
	cin >> n;
	vector<vector<int> > tree(n + 1);
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	int dist = 0;
	int farthest = dfs(1, tree, dist);
	dfs(farthest, tree, dist);
	cout << dist << '\n';
	return ;
}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}