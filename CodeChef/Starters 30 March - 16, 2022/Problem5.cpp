#include<bits/stdc++.h>
using namespace std;
#define fast_ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define vb vector<bool>
#define ll long long
#define vi vector<int>
#define vl std::vector<ll>
#define debug(a, n) for(int i = 0; i < n; i++){cerr << a[i] << ' ';} cerr<< '\n';
void solve(){
	int n;
	cin >> n;
	ll a[n];
	for(int i = 0;  i < n; i++){
		cin >> a[i] ;
	}
	ll b;
	for(int i = 0; i < n; i++){
		cin >> b;
		a[i] = b - a[i];
	}
	ll pre[n], suf[n];
	pre[0] = a[0];
	for(int i = 1; i < n; i++){
		pre[i] = min(a[i], pre[i - 1]);
	}
	suf[n - 1] = a[n - 1];
	for(int i = n - 2; i >= 0; i--){
		suf[i] = min(a[i], suf[i + 1]);
	}
	bool k = 1, p = 1, q = 1;
	for(int i = 0; i < n; i++){
		if(a[i] > suf[i] + pre[i]){
			k = 0;
		}
		if(a[i] > suf[i]){
			q = 0;
		}
		if(a[i] > pre[i]){
			p = 0;
		}
	}
	debug(pre, n)
	debug(suf, n)
	if(!k){
		cout << -1 << '\n';
		return ;
	}
	ll ans = 0;
	if(p & q){
		ans = min(a[0], a[n - 1]);
	}
	else if(p){
		ans = a[0];
	}
	else if(q){
		ans = a[n - 1];
	}
	else{
		ans = a[0] + a[n - 1];
	}
	cout << ans << '\n';


}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}