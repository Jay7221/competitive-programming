#include<bits/stdc++.h>
using namespace std;
#define ll long long
void print(ll k, ll P, vector<ll> L){
	cout << P << ' ' << k << "\n";
	for(int i = 1; i <= k; ++i){
		cout << L[i] << ' ' ;
	}
	cout << '\n';
}
ll getSum(ll P, ll k){
	// get sum P + (P + 1) + ... + (P + k - 1)
	ll sum = k * P + (k * (k - 1)) / 2;
	return sum;
}
void solve(ll n, ll m, ll s){
	if(m == 1){
		for(ll P = 1; P <= n; ++P){
			ll l = 1, r = n - P + 1;
			while(l < r){
				ll mid = (l + r + 1) / 2;
				if(getSum(P, mid) > s){
					r = mid - 1;
				}
				else{
					l = mid;
				}
			}
			if(getSum(P, l) == s){
				ll k = l;
				cout << P << ' ' << k << '\n';
				for(int i = 1; i <= k; ++i){
					cout << 1 << ' ' ;
				}
				cout << '\n';
				return;
			}
		}
		cout << -1 << '\n';
	}
	else{
		ll k = 1;
		vector<ll> L(n + 1);
		++L[k];
		s -= k;
		while((k + 1 <= n) && (k + 1 <= s)){
			++k;
			s -= k;
			++L[k];
		}
		for(ll i = k; i > 0; --i){
			ll q = min(m - 1, s / i);
			s -= q * i;
			L[i] += q;
		}
		print(k, 1ll, L);
	}
}
void solve(){
	ll n, m;
	cin >> n >> m;
	int q;
	cin >> q;
	while(q--){
		ll s;
		cin >> s;
		solve(n, m, s);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	t = 1;
	while(t--){
		solve();
	}

	return 0;
}
