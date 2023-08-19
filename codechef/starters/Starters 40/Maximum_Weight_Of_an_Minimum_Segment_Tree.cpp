#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for(int i = 0; i < m; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	ll ans = 0;
	int cnt = n - 1;
	int shift = 0;
	vector<bool> vis(m);
	for(int i = 0; i < m && cnt > 0; ++shift, --cnt, i += shift){
		ans += a[i];
		vis[i] = 1;
	}
	for(int i = m - 1; cnt > 0;--i){
		if(!vis[i]){
			ans += a[i];
			--cnt;
		}
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