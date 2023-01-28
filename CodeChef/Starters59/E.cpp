#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> allPoss;
void getPos(ll cur, int id, int mx){
	allPoss.push_back(cur);
	if(id == mx){
		return ;
	}
	getPos(cur + 5 * pow(10, id), id + 1, mx);
	getPos(cur + 6 * pow(10, id), id + 1, mx);
}
void solve(){
	string s;
	cin >> s;
	int n = s.size();
	int a, b, c, d, e, f, g;
	cin >> a >> b >> c >> d >> e >> f >> g;
	vector<ll> cost(10);
	cost[0] = a + b + c + d + e + f;
	cost[1] = b + c;
	cost[2] = a + b + d + e + g;
	cost[3] = a + b + c + d + g;
	cost[4] = b + c + f + g;
	cost[5] = a + c + d + f + g;
	cost[6] = a + c + d + e + f + g;
	cost[7] = a + b + c;
	cost[8] = a + b + c + d + e + f + g;
	cost[9] = a + b + c + d + f + g;
	ll ans = 1e9 + 7;
	auto add = [&](ll a, ll b, ll mod){
		return ((a + b) % mod);
	};
	auto divides = [&](ll p){
		ll cur = 0;
		for(ll i = 0; i < n; ++i){
			cur = add(cur * 10, s[i] - '0', p);
		}
		if(cur == 0)
			return true;
		return false;
	};
	auto price = [&](ll n){
		ll ans = 0;
		while(n){
			ans += cost[(n % 10)];
			n /= 10;
		}
		return ans;
	};
	ans = cost[1];
	if(divides(2)){
		ans = min(ans, cost[2]);
	}
	if(divides(5)){
		ans = min(ans, cost[5]);
	}
	for(auto p : allPoss){
		if(divides(p))
			ans = min(ans, price(p));
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	getPos(6, 1, 11);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}