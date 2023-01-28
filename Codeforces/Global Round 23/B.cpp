#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	int ans = 0, cnt = 0;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		cnt += (a[i] == 0);
	}
	for(int i = 0; i < cnt; ++i){
		ans += (a[i] == 1);
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