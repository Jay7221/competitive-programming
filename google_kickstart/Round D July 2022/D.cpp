#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c : a){cerr <<  c<< " " ;} cerr << '\n';
#define inf (int)(1e9 + 7)
#define prep(a) a.clear();	a.resize(n);
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int > > graph(n), g(n);
	vector<int> in(n), dp(n, 1);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		g[v].push_back(u);
		++in[v];
	}
	queue<int> q;
	for(int i = 0; i < n; ++i){
		if(in[i] == 0){
			q.push(i);
		}
	}
	while(q.size()){
		int u = q.front();
		q.pop();
		for(auto v : graph[u]){
			dp[v] += dp[u];
			--in[v];
			if(in[v] == 0){
				q.push(v);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(in[i] == 0 && dp[i] > k){
			++ans;
		}
	}
	auto bfs = [&](int u){
		int tmp = 0;
		vector<bool> vis(n);
		queue<int> q;
		vector<int> v;
		q.push(u);
		while(q.size()){
			int u = q.front();
			q.pop();
			vis[u] = 1;
			tmp += 1;
			if(in[u]){
				v.push_back(u);
			}
			for(auto c : g[u]){
				if(vis[c]){
					continue ;
				}
				q.push(c);
			}
		}
		for(auto c : v){
			if(tmp > k){
				++ans;
			}
			in[c] = 0;
		}
	};
	for(int i = 0; i < n; ++i){
		if(in[i]){
			bfs(i);
		}
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i < t + 1; ++i){
		cout << "Case #" << i << ": " ;
		solve();
	}
}