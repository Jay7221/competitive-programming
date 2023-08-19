#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	ll ans = 0;
	int s = 1;
	while(s < n)
		s *= 2;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		--a[i];
	}

	vector<int> tree(2 * s);
	auto query = [&](int l, int r){
		l += n, r += n;
		int ans = 0;
		while(l > 0 && r > 0 && l <= r){
			if(l % 2 == 1)
				ans += tree[l++];
			if(r % 2 == 0)
				ans += tree[r--];
			l /= 2, r /= 2;
		}
		return ans;
	};
	auto update = [&](int i, int k){
		i += n;
		while(i > 0){
			tree[i] += k;
			i /= 2;
		}
	};
	for(int i = n - 1; i > -1; --i){
		ans += query(0, a[i]);
		update(a[i], 1);
	}
	// for(int i = 0; i < n; ++i){
	// 	int a;
	// 	cin >> a;
	// 	--a;
	// 	ans += query(a, n - 1);
	// 	update(a, 1);
	// }
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