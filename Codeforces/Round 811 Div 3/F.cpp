#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, d12, d23, d31;
	cin >> n >> d12 >> d23 >> d31;
	int d1 = (d12 - d23 + d31) / 2, d2 = (-d12 + d23 + d31) / 2, d3 = (d12 + d23 - d31) / 2;
	if(min({d1, d2, d3}) < 0){
		cout << "NO\n";
		return ;
	}
	if(d1 + d2 + d3 > n - 1){
		cout << -1 << '\n';
	}
	cout << "YES\n";
	if(d1 == 0){

	}else if(d2 == 0){

	}else if(d3 == 0){

	}else{
		dfs(4, 1, d1);
		dfs(4, 1, d1);
		dfs(4, 1, d1);
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}