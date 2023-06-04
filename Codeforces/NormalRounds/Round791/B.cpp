#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll n, q;
	cin >> n >> q;
	vector<ll> a(n);
	ll sum = 0, x;
	map<ll, bool> used;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		sum += a[i];
		used[i] = 1;
	}
	auto debug = [&](map<ll, bool> m){
		for(auto c : m)
			cerr << c.second << ' ';
		cerr << '\n';
	};
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			ll i, p;
			cin >> i >> p;
			--i;
			if(used[i]){
				sum += p - a[i];
				a[i] = p;
			}else{
				used[i] = 1;
				sum += p - x;
				a[i] = p;
			}
		}else{
			cin >> x;
			sum = n * x;
			used.clear();
		}
		cout << sum << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}