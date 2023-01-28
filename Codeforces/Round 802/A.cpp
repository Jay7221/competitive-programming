#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll n, m, ans;
	cin >> n >> m;
	ans = (m * (m - 1 + n * (n + 1))) / 2ll;
	ll tmp = n + (m * n * (n - 1)) / 2ll + m * (n - 1) * (m - 1) + (m * (m + 1)) / 2ll - 1ll;
	ans = min(ans, tmp);
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