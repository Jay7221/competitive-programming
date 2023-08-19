#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<bool> > matrix(n, vector<bool>(m));
	bool gflag = 1;
	for(int i = 0; i < n; i += 2){
		bool flag = gflag;
		gflag ^= 1;
		for(int j = 0; j < m; j += 2){
			if(flag){
				matrix[i][j] =     1, 	matrix[i][j + 1] =     0;
				matrix[i + 1][j] = 0, 	matrix[i + 1][j + 1] = 1;
			}else{
				matrix[i][j] =     0, 	matrix[i][j + 1] =     1;
				matrix[i + 1][j] = 1, 	matrix[i + 1][j + 1] = 0;
			}
			flag ^= 1;
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main(){
	// freopen("inputf.in","r",stdin);
	// freopen("outputf.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}