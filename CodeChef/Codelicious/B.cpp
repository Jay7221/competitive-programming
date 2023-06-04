#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	int x = 0;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		x ^= a;
	}
	int LOGMAX = 30;
	int ans = LOGMAX + 1;
	for(int j = 0; j <= LOGMAX; ++j){
		if(x & (1 << j)){
			--ans;
		}
	}
	ans = min(ans, n);
	cout << ans << '\n';
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