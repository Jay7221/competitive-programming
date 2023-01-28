#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		long long a;
		cin >> a;
		ans = gcd(a, ans);
	}
	cout << n * ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}