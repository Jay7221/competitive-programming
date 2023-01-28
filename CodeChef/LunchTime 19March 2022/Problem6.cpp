#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
void solve(){
	ll n, q;
	cin >> n >> q;
	vi deg(n + 1, 0);
	for(int i = 0; i < n - 1; i++){
		ll u, v;
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ll k = deg[i];
		ans += ((k + 2) * (k - 1))/2;
	}
	ans += 1;
	ll qans = ans;
	cout << ans << '\n';
	for(int i = 0; i < q; i++){
		qans = ans;
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		if(deg[a] > 1)
			qans -= deg[a];
		if(deg[b] > 1)
			qans -= deg[b];
		deg[a]--;	deg[b]--;
		if(deg[c] > 0)
			qans += deg[c] + 1;
		if(deg[d] > 0)
			qans += deg[d] + 1;
		deg[a]++;	deg[b]++;
		cout << qans << '\n';
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}