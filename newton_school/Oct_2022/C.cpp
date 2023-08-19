#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
#define prep(a) a.clear();	a.resize(n);
vector<vector<int> > graph;
vector<int> dp, out, in;
int n, m;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	prep(graph)
	prep(in)
	prep(dp)
	prep(out)
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		++in[v];
		++out[u];
	}
	set<int> s;
	for(int i = 0; i < n; ++i){
		if(in[i] == 0){
			dp[i] = 1;
			s.insert(i);
		}
	}
	while(s.size()){
		set<int> ss;
		for(auto u : s){
			for(auto v : graph[u]){
				dp[v] += dp[u];
				--in[v];
				if(in[v] == 0){
					ss.insert(v);
				}
			}
		}
		s = ss;
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(out[i] == 0){
			ans += dp[i];
		}
	}
	cout << ans << '\n';
}