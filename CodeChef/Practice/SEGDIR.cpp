#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(int i = 0; i < a.size(); i++){cerr << i << " : " ;for(auto c : a[i]){cerr << c << ' ' ;} cerr << '\n';} cerr << '\n';
#define debug_2(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
vector<bool> visited;
vector<vector<int> > graph;
vector<bool> sides;			// which side will the ith line go
int n;
bool bfs(int root){
	queue<int> next;
	next.push(root);
	bool cur_side = 1;
	sides[root] = cur_side;
	visited[root] = 1;
	while(!next.empty()){
		cur_side ^= 1;
		queue<int> temp = next;
		while(!next.empty())
			next.pop();
		while(!temp.empty()){
			int cur = temp.front();
			temp.pop();
			visited[cur] = 1;
			sides[cur] = cur_side;
			for(auto neighbour : graph[cur]){
				if(visited[neighbour]){
					if(sides[neighbour] == sides[cur])
						return 0;
					continue ;
				}
				next.push(neighbour);
			}
		}
	} 
	return 1;
}
void solve(){
	cin >> n;
	vector<int> left(n), right(n);
	unordered_map<int, vector<int> > speeds;
	// speeds[i] stores the indexes of lines travelling at speed vi
	for(int i = 0; i < n; i++){
		cin >> left[i] >> right[i] ;
		int v;
		cin >> v;
		speeds[v].push_back(i);
	}
	graph.clear();
	visited.clear();
	sides.clear();
	graph.resize(n);
	visited.resize(n, 0);
	sides.resize(n, 0);
	for(auto v : speeds){
		vector<int> arr = v.second;
		// debug_2(arr)
		for(auto cur : arr){
			for(auto other : arr){
				if(cur == other)
					continue ;
				if(right[other] >= right[cur] && left[other] <= right[cur])
					graph[cur].push_back(other);
				else if(left[other] <= left[cur] && right[other] >= left[cur])
					graph[cur].push_back(other);
				else if(left[other] >= left[cur] && right[other] <= right[cur])
					graph[cur].push_back(other);

			}
		}
	}
	// debug(graph)
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			if(!bfs(i)){
				cout << "NO\n";
				return ;
			}
		}
	}
	cout << "YES\n";
}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}