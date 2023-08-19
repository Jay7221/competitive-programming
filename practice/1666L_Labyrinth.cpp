#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define pre(a) a.clear(); a.resize(n + 1);
int n, m, s;
vector<vector<int> > graph;
vector<int> par, q;
bool dfs(int cur, int z, int p){
	if(par[cur]){
		if(q[cur] == z || cur == s)
			return 0;
		cout << "Possible\n";
		vector<int> ans;
		int tmp = cur;
		while(tmp != -1){
			ans.push_back(tmp);
			tmp = par[tmp];
		}
		reverse(ans.begin(), ans.end());
		cout << ans.size() << '\n';
		for(auto c : ans)
			cout << c << ' ' ;
		cout << '\n';
		ans.clear();
		ans.push_back(cur);
		tmp = p;
		while(tmp != -1){
			ans.push_back(tmp);
			tmp = par[tmp];
		}
		reverse(ans.begin(), ans.end());
		cout << ans.size() << '\n';
		for(auto c : ans)
			cout << c << ' ' ;
		cout << '\n';
		ans.clear();
		return 1;
	}else{
		par[cur] = p;
		q[cur] = z;
	}
	for(auto c : graph[cur]){
		if(dfs(c, z, cur))
			return 1;
	}
	return 0;
}
void solve(){
	cin >> n >> m >> s;
	pre(graph)	pre(par)	pre(q)
	while(m--){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	par[s] = -1;
	int z = 1;
	bool flag = 1;
	for(auto c : graph[s]){
		if(dfs(c, z++, s)){
			flag = 0;
			return ;
		}
	}
	if(flag){
		cout << "Impossible\n";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}