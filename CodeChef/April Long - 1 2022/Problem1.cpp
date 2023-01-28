#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int a, b;
	cin >> a >> b;
	if(b - a < 2){
		cout << -1 << '\n';
		return ;
	}
	if(a % 2 == 0){
		cout << a << ' ' << a + 2 << '\n';
		return ;
	}
	if(b - a < 3){
		cout << -1 << '\n';
		return ;
	}
	if(a % 3 == 0){
		cout << a << ' ' << a + 3 << '\n';
		return ;
	}
	cout << a + 1 << ' ' << a + 3 << '\n';
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
	#endif
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}