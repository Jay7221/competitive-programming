#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	int q;
	cin >> q;
	vector<ll> a(n + 1), preSum(n + 1), preXor(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		preSum[i] = preSum[i - 1] + a[i];
		preXor[i] = preXor[i - 1] ^ a[i];
	}
	auto sum = [&](int i, int j){
		return (preSum[j] - preSum[i - 1]);
	};
	auto exor = [&](int i, int j){
		return (preXor[j] ^ preXor[i - 1]);
	};
	auto f = [&](int i, int j){
		return (sum(i, j) - exor(i, j));
	};
	int L, R;
	ll mx;
	while(q--){
		cin >> L >> R;
		mx = f(L, R);
		int l, r;
		l = L, r = R;
		while(l < r){
			int m = (l + r) / 2;
			if(f(L, m) == mx){
				r = m;
			}else{
				l = m + 1;
			}
		}
		R = l;
		l = L, r = R;
		while(l < r){
			int m = (l + r + 1) / 2;
			if(f(m, R) == mx){
				l = m;
			}else{
				r = m - 1;
			}
		}
		L = l;
		cout << L << ' ' << R << '\n';
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}