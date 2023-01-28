#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define inf (ll)(1e13 + 7)
void solve(){
	int n;
	ll x;
	cin >> n >> x;
	vector<ll> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	vector<ll> mx(n + 1, -inf);
	mx[0] = 0;
	for(int i = 0; i < n; i++){
		ll s = 0;
		for(int j = i; j < n; j++){
			s += a[j];
			mx[j - i + 1] = max(mx[j - i + 1], s);
		}
	}
	vector<ll> ans(n + 1);
	for(int k = 0; k < n + 1; k++){
		for(int l = 0; l < n + 1; l++){
			ans[k] = max(ans[k], mx[l] + x * min(l, k));
		}
	}
	for(int i = 0; i < n + 1; i++)
		cout << ans[i] << ' ';
	cout << '\n';
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