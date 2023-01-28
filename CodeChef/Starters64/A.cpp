#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int final = a[0];
	for(int i = 1; i < n; ++i)
		final = gcd(final, a[i]);
	int ans = 0;
	for(int i = 0; i < n; ++i)
		ans += (a[i] != final);
	cout << ans << '\n';
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