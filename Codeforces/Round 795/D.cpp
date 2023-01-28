#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define inf (ll)(1e15 + 7)
void solve(){
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(ll i = 0; i < n; ++i)
		cin >> a[i];
	bool flag = 1;
	ll sum = 0, mx = -inf;
	for(int i = 0; i < n; ++i){
		sum += a[i];
		mx = max(a[i], mx);
		if(mx < sum){
			flag = 0;
			break ;
		}
		if(sum < 0){
			sum = 0;
			mx = -inf;
		}
	}
	sum = 0, mx = -inf;
	for(int i = n - 1; i >= 0; --i){
		sum += a[i];
		mx = max(a[i], mx);
		cerr << mx << ' ' << sum << '\n';
		if(mx < sum){
			flag = 0;
			break ;
		}
		if(sum < 0){
			sum = 0;
			mx = -inf;
		}
	}
	if(flag)
		cout << "YES\n";
	else
		cout << "NO\n";
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