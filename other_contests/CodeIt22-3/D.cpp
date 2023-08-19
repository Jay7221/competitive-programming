#include<iostream>
using namespace std;
void solve(){
	int n;
	cin >> n;
	int p1 = 2, p2 = 4;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		if((a ^ p1 ^ p2) == 0){
			++ans;
		}
		p2 = p1;
		p1 = a;
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