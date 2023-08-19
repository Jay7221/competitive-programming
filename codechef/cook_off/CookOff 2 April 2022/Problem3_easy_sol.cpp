#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	int left[n], right[n];
	for(int i = 0; i < n; i++)
		cin >> left[i];
	for(int i = 0; i < n; i++)
		cin >> right[i];
	ll ans = 0;
	for(int i = 0; i < n - 1; i++)
		ans += min(right[i], left[i + 1]);
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}