#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	cout << n << ' ';
	for(int i = 1; i < n - 1; ++i){
		cout << i << ' ';
	}
	cout << n - 1 << '\n';
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