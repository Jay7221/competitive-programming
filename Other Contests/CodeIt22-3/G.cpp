#include<iostream>
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n][n];
	bool flag = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> a[i][j];
		}
	}
	for(int s = 0; s < 2 * n - 1; ++s){
		int i = 0;
		if(s > n - 1){
			i = s - n + 1;
		}
		if(flag){
			for(; (i < n) && (s - i >= 0); ++i){
				cout << a[i][s - i] << ' ';
			}
		}else{
			for(; (i < n) && (s - i >= 0); ++i){
				cout << a[s - i][i] << ' ';
			}
		}
		flag = 1 - flag;
	}
	cout << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}