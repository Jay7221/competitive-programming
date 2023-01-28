#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	int ans;
	if(n == 1 && m == 1){
		ans = 0;
	}else{
		ans = n - 1 + m - 1 + 1 + min(n - 1, m - 1);
	}
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}