#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	for(int i = 0; i < n; ++i){
		cin >> p[i];
	}
	int ans = 0;
	for(int i = 0; i < k; ++i)
		ans += (p[i] > k);
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
}