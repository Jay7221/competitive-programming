#include<bits/stdc++.h>
using namespace std;
class Solution {
#define prep(a) a.clear(); a.resize(n);
  public:
  vector<vector<int> > graph;
  vector<int> par, dp, dp1;
  void dfs(int u, int p = -1){
      par[u] = p;
      for(auto c : graph[u]){
          if(c == par[u]){
              continue ;
          }
          dfs(c, u);
          if(dp[u] < dp[c]){
          	dp[u] = dp[c];
          	dp1[u] = dp1[c];
          }
          else if(dp[u] == dp[c]){
          	dp1[u] += dp1[c];
          }
      }
  }
  void update(int u){
  	if(par[u] == -1)
  		return ;
  	if(dp[u] == dp[par[u]]){
  		dp1[par[u]] -= dp1
  	}
  }
    vector<int> solve(int n, int q, vector<vector<int> > &edge,
                      vector<vector<int> > &query) {
    	cerr << n << ' ' << q << '\n';
        // code here
        prep(graph)
        prep(par)
        prep(dp)
        dp1.clear();
        dp1.resize(n, 1);
        vector<int> ans;
        for(auto p : edge){
            int u, v;
            u = p[0], v = p[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(0);
        for(auto c : query){
            int u, v;
            u = c[0], v = c[1];
            if(u == par[v]){
                int tmp = dp[v];
                update(v);
                ans.push_back(dp[0]);
                update(v, tmp);
            }else{
                int tmp = dp[u];
                update(u);
                ans.push_back(dp[0]);
                update(u, tmp);
            }
        }
        return ans;
    }
};

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, q;
		cin >> n >> q;
		vector<vector<int> > e, qu;
		for(int i = 0; i < n - 1; ++i){
			int a, b;
			cin >> a >> b;
			vector<int> tmp = {a, b};
			e.push_back(tmp);
		}
		for(int i = 0; i < q; ++i){
			int a, b;
			cin >> a >> b;
			vector<int> tmp = {a, b};
			qu.push_back(tmp);	
		}
		Solution s;
		for(auto c : s.solve(n, q, e, qu)){
			cout << c << ' ';
		}
		cout << '\n';
	}
}