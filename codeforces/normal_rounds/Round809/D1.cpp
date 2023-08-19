#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int ans = inf;
	int tmp = 0;
	for(int i = 0; i < n; ++i){
		tmp = max(tmp, a[i] / k);
	}
	ans = min(ans, tmp);
	for(int mn = 1; mn <= a[0]; ++mn){
		tmp = 0;
		for(int i = 0; i < n; ++i){
			int p = min(a[i] / mn, k);
			tmp = max(tmp, a[i] / p - mn);
		}
		if(tmp == 0){
			cerr << mn << '\n';
		}
		ans = min(ans, tmp);
	}
	cout << ans << "\n";
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