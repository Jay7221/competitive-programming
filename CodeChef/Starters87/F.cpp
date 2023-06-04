#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int LOGMAX = 31;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	
	vector<int> pre(n);
	vector<int> last(LOGMAX, -1);
	map<int, vector<int>> indices;
	int xo = 0;
	indices[0].push_back(-1);
	for(int i = 0; i < n; ++i){
		xo ^= a[i];
		indices[xo].push_back(i);
		pre[i] = xo;
	}
	auto debug = [&](vector<int> &v){
		for(int elem : v){
			cerr << elem << ' ' ;
		}
		cerr << '\n';
	};
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 31; ++j){
			if((a[i] & (1 << j))){
				last[j] = i;
			}
		}
		vector<int> tmp = last;
		sort(tmp.rbegin(), tmp.rend());
		int bx = i;
		int OR = a[i];
		for(int j = 0; j < LOGMAX; ++j){
			int ax = tmp[j] + 1;
			if(ax > bx){
				continue;
			}
			int x = (OR ^ pre[i]);
			int tmp = lower_bound(indices[x].begin(), indices[x].end(), bx) - lower_bound(indices[x].begin(), indices[x].end(), ax - 1);
			ans += tmp;
			OR |= a[ax - 1];
			bx = ax - 1;
		}
	}
	ans = (n * 1ll * (n + 1)) / 2 - ans;
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
	
	return 0;
}