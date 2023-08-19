#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
ll cost(ll x, ll k){
	ll val = (x - k) / (k + 1);
	ll rem = (x - k) % (k + 1);
	return k + (k + 1 - rem) * val * (val + 1) / 2 + rem * (val + 1) * (val + 2) / 2;
}
void solve(){
	ll n;
	cin >> n;
	ll k ;
	cin >> k;
	vector<ll> arr(n);
	for(ll i = 0;i < n ; i++)
		cin >> arr[i];
	ll conse = 1;
	ll ans = 0;
	priority_queue<tuple<ll, ll, ll> > s;
	for(ll i= 0; i < n ;i++){
		while(i + 1 < n && arr[i] == arr[i + 1]){
			i++;
			conse++;
		}
		ans += conse * (conse + 1) / 2;
		s.push({-cost(conse, 1) + cost(conse, 0), conse, 1});
		conse = 1;
	}
	while(!s.empty() && k--){
		ll a, b, c;
		tie(a, b, c) = s.top();
		s.pop();
		// cerr << a << ' ' << b << ' ' << c << '\n';
		ans -= a;
		if(b >= c + 1){
			s.push({-cost(b, c + 1) + cost(b, c), b, c + 1});
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