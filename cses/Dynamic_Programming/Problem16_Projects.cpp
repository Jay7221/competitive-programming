#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> x(n), y(n), z(n);
	map<int, int> compress;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i] >> z[i];
		y[i]++;
		compress[x[i]], compress[y[i]];
	}
	int coords = 0;
	for(auto &v : compress){
		v.second = coords++;
	}
	vector<vector<pair<int, int> > > projects(coords);
	// projects[i] = number of projects ending on day i, cost of the project
	for(int i = 0; i < n; i++){
		projects[compress[y[i]]].push_back({compress[x[i]], z[i]});
	}
	vector<ll> dp(coords, 0);
	for(int i = 0; i < coords; i++){
		if(i > 0)
			dp[i] = dp[i - 1];
		for(auto p : projects[i]){
			dp[i] = max(dp[i], dp[p.first] + p.second);
		}
	}
	cout << dp[coords - 1] << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}