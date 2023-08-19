#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll n, k1, k2;
	cin >> n ;
	vector<ll> a(n), b(n), c(n);
	for(ll i = 0; i < n; i++)
		cin >> a[i];
	for(ll i = 0; i < n; i++)
		cin >> b[i];
	for(ll i = 0; i < n; i++)
		cin >> c[i];
	for(ll i = 0; i < n; i++){
		a[i] = max(a[i] - c[i], 0ll);
		b[i] = max(b[i] - c[i], 0ll);
		b[i] = max(b[i] - a[i], 0ll);
	}
	vector<ll> k = a;
	cin >> k1 >> k2;
	ll ans = 0;
	ans = accumulate(c.begin(), c.end(), 0ll);
	vector<pair<ll, ll> > p(n), q(n);
	for(int i = 0; i < n; i++){
		p[i] = {b[i], i};
		q[i] = {a[i], i};
	}
	vector<bool> mark(n, 0);
	sort(p.rbegin(), p.rend());
	sort(q.rbegin(), q.rend());
	for(int i = 0; i < min(n, k2); i++){
		if(p[i].first > 0){
			ans += p[i].first + k[i];
			mark[i] = 1;
		}
	}
	ll cnt = 0;
	for(ll i = 0; i < q.size() && cnt < k1; i++){
		if(mark[i])
			continue ;
		ans += a[i];

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