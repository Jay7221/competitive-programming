#include<bits/stdc++.h>
using namespace std;
#define ll long long
void print(vector<int> &tree){
	int sz = tree.size();
	for(int i = 0; i < sz; ++i){
		cerr << tree[i] << ' ';
	}
	cerr << '\n';
}
void solve(){
	int n;
	cin >> n;
	int L, R;
	cin >> L >> R;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int sz = 1;
	while(sz < n){
		sz <<= 1;
	}
	vector<int> tree(2 * sz);
	for(int i = 0; i < n; ++i){
		tree[i + sz] = a[i];
	}
	for(int i = sz - 1; i >= 0; --i){
		tree[i] = gcd(tree[2 * i], tree[2 * i + 1]);
	}
	auto get = [&](int l, int r){
		l += sz;
		r += sz;
		int ans = 0;
		while(l <= r){
			if(l % 2 == 1){
				ans = gcd(ans, tree[l]);
				++l;
			}
			if(r % 2 == 0){
				ans = gcd(ans, tree[r]);
				--r;
			}
			l /= 2;
			r /= 2;
		}
		return ans;
	};
	auto getL = [&](int i){
		int l = i, r = n - 1;
		if(get(i, r) > R){
			return n;
		}
		while(l < r){
			int m = (l + r) / 2;
			if(get(i, m) <= R){
				r = m;
			}else{
				l = m + 1;
			}
		}
		return l;
	};
	auto getR = [&](int i){
		if(a[i] < L){
			return i - 1;
		}
		int l = i, r = n - 1;
		while(l < r){
			int m = (l + r + 1) / 2;
			if(get(i, m) >= L){
				l = m;
			}else{
				r = m - 1;
			}
		}
		return r;
	};
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		int l = getL(i), r = getR(i);
		// cerr << i << ' ' << l << ' ' << r << '\n';
		ans += max(0, r - l + 1);
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		solve();
	}

	return 0;
}
