#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, x;
	cin >> n >> x;
	int mn = 1e9 + 3;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mn = min(mn, a[i]);
	}
	int ans = n;
	ans = max(ans, x / mn + (x % mn != 0));
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
}