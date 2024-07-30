#include<iostream>
using namespace std;
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
	}
	cout << 1 << ' ' << n << '\n';
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