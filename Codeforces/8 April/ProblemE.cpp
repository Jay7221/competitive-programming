#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX_INT (1 << 30)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
struct segment_tree{
	int n;
	vector<int> tree;
	segment_tree(vector<int> a){
		tree.clear();
		int k = a.size();
		n = 1;
		while(n < k){
			n *= 2;
		}
		tree.resize(2 * n, MAX_INT);
		for(int i = 0; i < n; i++){
			tree[i + n] = a[i];
		}
		for(int i = n - 1; i > 0; i--){
			tree[i] = min(tree[2 * i], tree[2 * i + 1]);
		}
	}
	int range_q(int a, int b){
		a += n;		b += n;
		// cerr << a << ' ' << b << '\n';
		int ans = MAX_INT;
		while(a <= b){
			if(a % 2 == 1)
				ans = min(ans, tree[a++]);
			if(b % 2 == 0)
				ans = min(ans, tree[b--]);
			a /= 2;
			b /= 2;
		}
		return ans;
	}


};
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> or_arr(n - 1);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n - 1; i++){
		or_arr[i] = (a[i] | a[i + 1]);
	}
	segment_tree tree(or_arr);
	// debug(tree.tree)
	int m;
	cin >> m;
	while(m--){
		int l, r;
		cin  >> l >> r;
		l--;	r--;
		cout << tree.range_q(l, r - 1) << '\n';
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
}