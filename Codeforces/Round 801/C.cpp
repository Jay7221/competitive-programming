#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > dp1(n, vector<int>(m)), dp2(n, vector<int>(m)), a(n, vector<int>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> a[i][j];
		}
	}
	if((n + m - 1) % 2 == 1){
		cout << "NO\n";
		return ;
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(i > 0){
				dp1[i][j] = max(dp1[i][j], dp1[i - 1][j]);
				dp2[i][j] = max(dp2[i][j], dp2[i - 1][j]);
			}
			if(j > 0){
				dp1[i][j] = max(dp1[i][j], dp1[i][j - 1]);
				dp2[i][j] = max(dp2[i][j], dp2[i][j - 1]);
			}
			dp1[i][j] += (a[i][j] == 1);
			dp2[i][j] += (a[i][j] == -1);
		}
	}
	if((dp1[n - 1][m - 1] < (n + m - 1) / 2)){
		cout << "NO\n";
		return ;
	}
	if(dp2[n - 1][m - 1] < (n + m - 1) / 2){
		cout << "NO\n";
		return ;
	}
	cout << "YES\n";
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