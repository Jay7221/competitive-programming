#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ;}cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int mn = *min_element(a.begin(), a.end());
	for(int i = 0; i < n; ++i)
		a[i] -= mn;
	int ans = abs(mn);
	ans += a[0];
	int cur = mod;
	for(int i = 0; i < n; ++i){
		cur = min(cur, a[i]);
		a[i] -= cur;
	}
	ans += a[n - 1];
	cur = mod;
	for(int i = n - 1; i > -1; --i){
		cur = min(cur, a[i]);
		a[i] -= cur;
	}
	for(int i = 0; i < n; ++i){
		ans += a[i] * 3;
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
}