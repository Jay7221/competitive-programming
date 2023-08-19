#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	vector<int> freq(n + 1);
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		++freq[x];
		v.push_back({x, i});
	}
	sort(v.begin(), v.end());
	vector<int> p;
	for(auto [x, ind] : v){
		p.push_back(ind);
	}
	int cnt = 0;
	vector<bool> vis(n);
	auto dfs = [&](int u){
		int ans = 0;
		while(!vis[u]){
			vis[u] = true;
			u = p[u];
			++ans;
		}
		while(ans > 3){
			ans -= 2;
		}
		if(ans == 2){
			++cnt;
		}
	};
	for(int i = 0; i < n; ++i){
		if(!vis[i]){
			dfs(i);
		}
	}
	string ans = "NO";
	if(cnt % 2 == 0){
		ans = "YES";
	}
	for(int i = 0; i <= n; ++i){
		if(freq[i] > 1){
			ans = "YES";
		}
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

	return 0;
}
