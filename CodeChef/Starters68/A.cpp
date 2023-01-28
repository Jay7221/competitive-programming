#include<iostream>
using namespace std;
void solve(){
	int n, c, x;
	cin >> n >> x >> c;
	int sum = 0;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		sum += max(a, x - c);
	}
	cout << sum << '\n';
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