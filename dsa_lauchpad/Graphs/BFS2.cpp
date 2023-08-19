#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cout << "Enter number of nodes : ";
	cin >> n;
	cout << endl;
	cout << "Enter number of edges : ";
	cin >> m;
	cout << endl;
	vector<vector<int> > graph(n);
	vector<bool> vis(n);
	int u, v;
	for(int i = 0; i < m; ++i){
		cout << "Enter edges u v : ";
		cin >> u >> v;
		cout << endl;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> time(n);
	queue<int> q;
	vector<int> arr;
	vector<int> q;
	q.push_back(0);
	int cur = 0;
	while(v.size()){
		for(auto u : q){
			vis[u] = 1;
			time[u] = cur;
			for(auto v : graph[u]){
				if(vis[v]){
					continue ;
				}
				tmp.push_back(v);
			}
		}
		cur += 1;
		q = tmp;
	}
	for(auto elem : arr){
		cout << elem << ' ';
	}
	cout << endl;
	return 0;
}
