#include<bits/stdc++.h>
using namespace std;
void solve(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int sum = a + b + c  + d;
	if(sum == 0){
		cout << 0 << '\n';
	}else if(sum < 4){
		cout << 1 << '\n';
	}else{
		cout << 2 << '\n';
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}