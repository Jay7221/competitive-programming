#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c : a){ cerr << c << ' ' ; } cerr << '\n';
void solve(){
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	vector<ll> pre(n), suf(n);
	for(int i = 1; i < n; ++i){
		pre[i] = pre[i - 1] + max(0ll, a[i - 1] - a[i]);
	}
	for(int i = n - 2; i > -1; --i){
		suf[i] = suf[i + 1] + max(0ll, a[i + 1] - a[i]);
	}
	while(m--){
		int p, q;
		cin >> p >> q;
		--p, --q;
		if(p > q){
			cout << suf[q] - suf[p] << '\n';
		}else{
			cout << pre[q] - pre[p] << '\n';
		}
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}