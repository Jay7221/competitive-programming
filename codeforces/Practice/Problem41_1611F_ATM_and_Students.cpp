#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	ll s;
	cin >> s;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int L, R, ans = -1;
	int l = 0;
	ll cur = s;
	for(int r = 0; r < n; ++r){
		cur += a[r];
		while((l <= r) && cur < 0){
			cur -= a[l];
			++l;
		}
		if(r - l + 1 > ans){
			L = l, R = r;
			ans = r - l + 1;
		}
	}
	++L, ++R;
	if(ans > 0){
		cout << L << ' ' << R << '\n';
	}else{
		cout << -1 << '\n';
	}
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

	return 0;
}
