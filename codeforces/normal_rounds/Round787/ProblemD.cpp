#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> par(n + 1);
	vector<bool> leave(n + 1, 1);
	for(int i = 1; i < n + 1; i++){
		cin >> par[i];
		if(par[i] == i)
			continue ;
		leave[par[i]] = 0;
	}
	vector<stack<int> > paths;
	vector<bool> visited(n + 1);
	visited[0] = 1;
	for(int i = n; i > 0; i--){
		if(!leave[i])
			continue ;
		visited[i] = 1;
		stack<int> cur_path;
		cur_path.push(i);
		while(!visited[par[cur_path.top()]]){
			cur_path.push(par[cur_path.top()]);
			visited[cur_path.top()] = 1;
		}
		paths.push_back(cur_path);
	}
	cout << paths.size() << '\n';
	for(auto c : paths){
		cout << c.size() << '\n';
		while(c.size()){
			cout << c.top() << ' ';
			c.pop();
		}
		cout << '\n';
	}
	cout << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}