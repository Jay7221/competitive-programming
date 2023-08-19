#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, down, up;
	cin >> n >> down >> up;
	string s;
	cin >> s;
	string ans = s;
	vector<int> up_cost(n), down_cost(n);
	for(int i = 0; i < n; ++i){
		up_cost[i] = s[i] - 'a';
		down_cost[i] = 1 + ('z' - s[i]);
	}
	auto is_okay = [&](int k){
		set<pair<int, int>> st;
		int up_tmp = up, down_tmp = down;
		for(int i = 0; i <= k; ++i){
			up_tmp -= up_cost[i];
			st.insert({down_cost[i], i});
		}
		while(st.size()){
			int val, ind;
			tie(val, ind) = *st.begin();
			if(val > down_tmp){
				break;
			}
			st.erase(st.begin());
			down_tmp -= down_cost[ind];
			up_tmp += up_cost[ind];
		}
		return (up_tmp >= 0);
	};
	auto apply = [&](int k){
		set<pair<int, int>> st;
		for(int i = 0; i <= k; ++i){
			ans[i] = 'a';
			up -= up_cost[i];
			st.insert({down_cost[i], i});
		}
		while(st.size()){
			int val, ind;
			tie(val, ind) = *st.begin();
			if(val > down){
				break;
			}
			st.erase(st.begin());
			down -= down_cost[ind];
			up += up_cost[ind];
		}
		for(int i = 0; i < n; ++i){
			int tmp = 1 + ('z' - ans[i]);
			if(tmp <= down){
				down -= tmp;
				ans[i] = 'a';
			}
		}
		for(int i = 0; i < n; ++i){
			int tmp = ans[i] - 'a';
			ans[i] -= min(tmp, up);
			up -= min(tmp, up);
		}
	};
	int l = -1, r = n - 1;
	while(l < r){
		int m = (l + r + 1) / 2;
		if(is_okay(m)){
			l = m;
		}else{
			r = m - 1;
		}
	}
	apply(l);
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
}
