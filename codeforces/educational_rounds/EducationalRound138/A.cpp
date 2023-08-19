#include<iostream>
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int x, y;
		cin >> x >> y;
	}
	if(n > m){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
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