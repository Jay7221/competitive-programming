#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> degree(n + 1, 0);
	vector<int> team(n + 1, 1);
	vector<vector<int> > graph(n + 1);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		degree[u]++;
		degree[v]++;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	if(m % 2 == 0){
		cout << 1 << '\n';
		for(int i = 1; i < n + 1; i++)
			cout << team[i] << ' ';
		cout << '\n';
		return ;
	}
	bool done = 0;
	int rem;
	for(int i = 1; i < n + 1; i++){
		if(degree[i] % 2){
			done = 1;
			team[i] = 2;
			cout << 2 << '\n';
			break;
		}
		if(degree[i] >= 1)
			rem = i;
	}
	if(!done){
		cout << 3 << '\n';
		team[rem] = 2;
		team[graph[rem][0]] = 3;
	}
	for(int i = 1; i < n + 1; i++)
		cout << team[i] << ' ' ;
	cout << '\n';
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
	#endif
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}