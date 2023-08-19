#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
class MinSegTree{
	public:
		int n;
		vector<int> tree;
		MinSegTree(int sz){
			n = 1;
			while(n < sz){
				n *= 2;
			}
			tree.assign(2 * n, INF);
		}
		void set(int ind, int val){
			ind += n;
			tree[ind] = val;
			ind /= 2;
			while(ind > 0){
				tree[ind] = min(tree[2 * ind], tree[2 * ind + 1]);
				ind /= 2;
			}
		}
		int query(int l, int r){
			l += n, r += n;
			int ans = INF;
			while(l <= r){
				if(l % 2 == 1){
					ans = min(ans, tree[l]);
					++l;
				}
				if(r % 2 == 0){
					ans = min(ans, tree[r]);
					--r;
				}
				l /= 2;
				r /= 2;
			}
			return ans;
		}
};
void print(vector<int> &v){
	for(int elem : v){
		cerr << elem << ' ';
	}
	cerr << '\n';
}
void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i){
		cin >> b[i];
	}
	vector<int> dp(n + 1, INF), backlink(n + 1, -1);
	int l = n;
	for(int r = n; r > 0; --r){
		int u = r + b[r];
		while(l >= u - a[u]){
			backlink[l] = r;
			--l;
		}
	}
	if(backlink[0] == -1){
		cout << -1 << '\n';
		return;
	}
	vector<int> ans;
	int cur = 0;
	while(cur != n){
		ans.push_back(cur);
		cur = backlink[cur];
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(int elem : ans){
		cout << elem << ' ';
	}
	cout << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}