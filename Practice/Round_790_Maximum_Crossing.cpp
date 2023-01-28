#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
struct Seg{
public:
	int n;
	vector<int> tree;
	Seg(int s);
	void update(int ind, int k);
	int query(int l, int r);
};
Seg::Seg(int s){
	n = 1;
	while(n < s)
		n = (n << 1);
	tree.resize(2 * n);
}
void Seg::update(int ind, int k){
	ind += n;
	while(ind > 0){
		tree[ind] += k;
		ind /= 2;
	}
}
int Seg::query(int l, int r){
	int ans = 0;
	l += n, r += n;
	while(l > 0 && r > 0 && l <= r){
		if(l % 2 == 1){
			ans += tree[l++];
		}
		if(r % 2 == 0){
			ans += tree[r--];
		}
		l /= 2, r /= 2;
	}
	return ans;
}
void solve(){
	int n;
	cin >> n;
	ll ans = 0;
	Seg tree(n);
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		--a;
		ans += tree.query(a, n - 1);
		tree.update(a, 1);
	}
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