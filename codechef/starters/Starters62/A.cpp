#include<bits/stdc++.h>
using namespace std;
void solve(){
	int a, b;
	cin >> a >> b;
	int x = b - 2 * a;
	if(a == b){
		cout << "YES\n";
		return ;
	}
	if(x < 0){
		cout << "NO\n";
	}else{
		cout << "YES\n";
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