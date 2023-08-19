#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > Map(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> Map[i][j];
		}
	}
	int ans = Map[0][0];
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < m - 1; j++){
			if(Map[i][j] > Map[i + 1][j] + Map[i][j + 1]){
				cout << "NO\n";
				return ;
			}
		}
	}
	for(int i = 1; i < n + m - 1; i++){
		int sum = 0;
		int x, y;
		if(n > m){
			if(i < n){
				x = i, y = 0;
			}
			else{
				x = n - 1, y = i - n + 1;
			}
			while(x >= 0 && y < m){
				sum += Map[x][y];
				x--;	y++;
			}
		}
		else{
			if(i < m){
				x = 0, y = i;
			}
			else{
				x = i - m + 1, y = m - 1;
			}
			while(y >= 0 && x < n){
				sum += Map[x][y];
				x++;	y--;
			}
		}
		if(ans != sum){
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
	return ;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
