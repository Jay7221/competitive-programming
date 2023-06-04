#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int cur = a[0];
	for(auto elem : a)
		cur = gcd(cur, elem);
	int ans = n;
	if(cur == 1)
		ans = 0;
	for(int i = n; i > 0; --i){
		if(gcd(cur, i) == 1){
			ans = min(ans, n - i + 1);
		}
	}
	ans = min(ans, 3);
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