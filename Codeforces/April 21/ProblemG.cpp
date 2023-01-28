#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
vector<vector<char> > grid;
int n, m;
void fall(int i, int j){
	int t = i;
	while(t < n){
		if(t + 1 > n - 1)
			break ;
		if(grid[t + 1][j] == 'o' || grid[t + 1][j] == '*')
			break ;
		t++;
	}
	grid[i][j] = '.';
	grid[t][j] = '*';
}
void solve(){
	cin >> n >> m;
	grid.clear();
	grid.resize(n, vector<char>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cin >> grid[i][j];
	}
	for(int i = n - 1; i > -1; i--){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == '*')
				fall(i, j);
		}
	}
	for(auto c : grid){
		for(auto k : c)
			cout << k;
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