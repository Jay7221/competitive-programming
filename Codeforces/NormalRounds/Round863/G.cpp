#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> c(n);
	vector<vector<int>> ind(n, vector<int>());
	for(int i = 0; i < n; ++i){
		cin >> c[i];
		--c[i];
		ind[c[i]].push_back(i);
	}
	vector<vector<int>> graph(n);
	for(int color = 0; color < n; ++color){
		for(int i = 0; i + k < ind[color].size(); ++i){
			graph[ind[color][i]].push_back(ind[color][i + k]);
		}
	}
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

	return 0;
}
