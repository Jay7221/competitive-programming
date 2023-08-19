#include<iostream>
using namespace std;
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
	}
	int d = 10 - n;
	int ans = 3 * d * (d - 1);
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}