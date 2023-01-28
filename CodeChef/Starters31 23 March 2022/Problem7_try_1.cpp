#include<bits/stdc++.h>
using namespace std;
#define debug(a, n) for(int i = 0; i < n; i++){cerr << a[i] << ' ' ;} cerr << '\n';
#define debug_2(a, n, m) for(int i = 0; i < n; i++){for(int j = 0; j < m;j++){cerr << a[i][j] << '\t';} cerr << '\n';}cerr << '\n';
#define ll long long
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<bool> > Map(n, vector<bool>(m));
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			Map[i][j] = s[j] - '0';
		}
	}
	vector<vector<int> > trav(n, vector<int>(m, 0));
	trav[0][0] = k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int no = trav[i][j];
			bool city = Map[i][j];
			if(i + 1 < n){
				if(city == 1){
					trav[i + 1][j] += (no + 1) / 2;
				}
				else{
					trav[i + 1][j] += no / 2;
				}
			}
			if(j + 1 < m){
				if(city == 0){
					trav[i][j + 1] += (no + 1) / 2;
				}
				else{
					trav[i][j + 1] += no / 2;
				}
			}
		}
	}
	int i = 0, j = 0;
	bool val;
	while(i < n && j < m){
		int t = trav[i][j];
		val = Map[i][j];
		if(i == n - 1){
			if(t > 1){
				break ;
			}
		}
		if(j == m - 1){
			if(t > 1){
				break ;
			}
		}
		if(t % 2 == 0){
			val ^= 1;
		}
		if(val == 1){
			i++;
		}else{
			j++;
		}
	}
	i++; 	j++;
	if(i > n){i--;}
	if(j > m){j--;}
	cout << i << ' ' << j << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}