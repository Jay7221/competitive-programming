#include<bits/stdc++.h>
using namespace std;
#define ll long long
class AvoidRoads{
public:
	ll numWays(int n, int m, vector<string>& bad){
		map<pair<int, int>, set<pair<int, int> > > mp;
		for(int i = 0; i < n + 1; ++i){
			for(int j = 0; j < m + 1; ++j){
				mp[{i + 1, j}].insert({i, j});
				mp[{i, j + 1}].insert({i, j});
			}
		}
		for(auto s : bad){
			int a = s[0] - '0', b = s[2] - '0', c = s[4] - '0', d = s[6] - '0';
			mp[{a, b}].erase({c, d});
			mp[{c, d}].erase({a, b});
		}
		vector<vector<ll> > dp(n + 1, vector<ll>(m + 1, 0));
		dp[0][0] = 1;
		for(int i = 0; i < n + 1; ++i){
			for(int j = 0; j < m + 1; ++j){
				for(auto ss : mp[{i, j}]){
					int x, y;
					tie(x, y) = ss;
					dp[i][j] += dp[x][y];
				}
			}
		}
		return dp[n][m];
	}
};
int main(){
	int n, m;
	cin >> n >> m;
	vector<string> bad = {"0 0 1 0", "1 2 2 2", "1 1 2 1"};
	AvoidRoads a;
	cout << a.numWays(n, m, bad) << '\n';
}