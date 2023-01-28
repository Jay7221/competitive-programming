#include<iostream>
using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	bool flag = false;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		flag = (flag | a);
	}
	if(flag)
		cout << "YES\n";
	else
		cout << "NO\n";
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