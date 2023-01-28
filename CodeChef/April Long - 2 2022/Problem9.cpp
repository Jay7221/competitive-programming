#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void debug(map<pair<ll, ll>, ll> m){
	for(auto c:  m){
		cerr << c.first.first << ' ' << c.first.second << ":" << '\t' << c.second << '\n';
	}
	cerr << '\n';
}
void solve(){
	ll n;
	cin >> n;
	vector<pair<ll, ll> > points(n);
	for(ll i = 0; i < n; i++){
		ll x, y;
		cin >> x >> y;
		points[i] = {x, y};
	}
	auto gcd = [&](ll a, ll b){
		a = abs(a), b = abs(b);
		while(b){
			ll t = b;
			b = a % b;
			a = t;
		}
		return a;
	};
	auto slope = [&](pair<ll, ll> a, pair<ll, ll> b){
		ll dx = a.first - b.first, dy = a.second - b.second;
		ll d = gcd(dx, dy);
		dx /= d, dy /= d;
		if(dx * dy > 0){
			if(dx < 0)
				dx *= -1, dy *= -1;
		}else if(dx * dy < 0){
			dx = -1 * abs(dx), dy = abs(dy);
		}else{
			dx = abs(dx), dy = abs(dy);
		}
		pair<ll, ll> ans = {dx, dy};
		return ans;
	};
	auto perpendicular = [&](pair<ll, ll> s){
		ll x , y;
		tie(x, y) = s;
		pair<ll, ll> ans;
		if(x * y < 0)
			ans = {y, -x};
		else if(x * y > 0)
			ans = {-y, x};
		else
			ans = {y, x};
		return ans;
	};
	ll ans = 0;
	for(ll i = 0; i < n; i++){
		map<pair<ll, ll>, ll> freq;
		for(ll j = 0; j < n; j++){
			if(i == j)
				continue; 
			freq[slope(points[i], points[j])]++;
		}
		for(auto c : freq){
			pair<ll, ll> p = perpendicular(c.first);
			ans += c.second * freq[p];
			if(c.second * freq[p] == 0)
				continue;
		}
	}
	cout << ans / 2 << '\n';
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