#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct MaxSegTree{
	int n;
	vector<ll> tree;
	MaxSegTree(vector<ll>& a){
		n = 1;
		while(n < a.size()){
			n <<= 1;
		}
		tree.resize(2 * n);
		for(int i = 0; i < a.size(); ++i){
			tree[i + n] = a[i];
		}
		for(int i = n - 1; i > 0; --i){
			tree[i] = max(tree[2 * i], tree[2 * i + 1]);
		}
	}
	ll query(int l, int r){
		l += n, r += n;
		ll ans = 0;
		while(l <= r){
			if(l % 2 == 1){
				ans = max(ans, tree[l]);
				++l;
			}
			if(r % 2 == 0){
				ans = max(ans, tree[r]);
				--r;
			}
			l /= 2;
			r /= 2;
		}
		return ans;
	}
};
void solve(){
	ll n, m;
	cin >> n >> m;
	vector<ll> a(m);
	for(int i = 0; i < m; ++i){
		cin >> a[i];
	}
	MaxSegTree t(a);
	int q;
	cin >> q;
	while(q--){
		ll xs, ys, xf, yf, k;
		cin >> xs >> ys >> xf >> yf >> k;
		--ys, --yf;
		if(ys > yf){
			swap(ys, yf);
		}
		if(((xs - xf) % k != 0) || ((ys - yf) % k != 0)){
			cout << "NO\n";
			continue ;
		}
		ll mx = t.query(ys, yf);
		ll mx_reach = xs + ((n - xs) / k) * k;
		if(mx_reach > mx){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}