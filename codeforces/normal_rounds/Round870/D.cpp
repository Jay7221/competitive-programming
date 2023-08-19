#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<int> b(n), a(n), c(n);
	for(int i = 0; i < n; ++i){
		cin >> b[i];
		a[i] = i + b[i];
		c[i] = b[i] - i;
	}
	for(int i = 1; i < n; ++i){
		a[i] = max(a[i], a[i - 1]);
	}
	for(int i = n - 2; i >= 0; --i){
		c[i] = max(c[i], c[i + 1]);
	}
	int ans = 0;
	for(int i = 1; i < n - 1; ++i){
		ans = max(ans, a[i - 1] + b[i] + c[i + 1]);
	}
	cout << ans << '\n';
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