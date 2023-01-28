#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int mx = a[0];
	for(int i = 1; i < n; ++i){
		a[0] = gcd(a[0], a[i]);
		mx = max(mx, a[i]);
	}
	cout << (mx / a[0]) << '\n';
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