#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	if(n < 3){
		cout << -1 << '\n';
		return ;
	}
	int a[n][n];
	for(int i = 0; i < n; ++i){
		a[i][0] = 1;
		for(int j = 1; j < n; ++j){
			a[i][j] = 0;
		}
	}
	int j = n - 1;
	for(int i = 1; i < n; ++i){
		a[i][j] = 1;
		--j;
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << a[i][j];
		}
		cout << '\n';
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
