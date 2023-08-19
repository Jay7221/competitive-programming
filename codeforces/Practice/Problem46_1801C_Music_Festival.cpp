#include<bits/stdc++.h>
using namespace std;
#define ll long long
void debug(vector<int> v){
	for(int elem : v){
		cerr << elem << ' ';
	}
	cerr << '\n';
}
void solve(){
	int n;
	cin >> n;
	vector<vector<int>> a(n);
	for(int i = 0; i < n; ++i){
		int k;
		cin >> k;
		a[i].assign(k, 0);
		for(int j = 0; j < k; ++j){
			cin >> a[i][j];
		}
	}
	vector<vector<int>> b(n);
	set<int> st;
	map<int, int> mp;
	for(int i = 0; i < n; ++i){
		int k = a[i].size();
		int cur = 0;
		vector<int> B;
		for(int j = 0; j < k; ++j){
			if(a[i][j] > cur){
				cur = a[i][j];
				B.push_back(cur);
				st.insert(cur);
			}
		}
		b[i] = B;
	}
	int mx = 0;
	for(int elem : st){
		mp[elem] = mx;
		++mx;
	}
	vector<vector<pair<int, int>>> graph(mx);
	for(int i = 0; i < n; ++i){
		int m = b[i].size();
		for(int j = 0; j < m; ++j){
			b[i][j] = mp[b[i][j]];
		}
		for(int j = 0; j < m; ++j){
			int l = b[i][j], r = b[i][m - 1], w = m - j;
			graph[l].push_back({r, w});
		}
	}
	vector<int> dp(mx + 1);
	for(int i = mx - 1; i >= 0; --i){
		dp[i] = dp[i + 1];
		for(auto [j, w] : graph[i]){
			dp[i] = max(dp[i], dp[j + 1] + w);
		}
	}
	int ans = *max_element(dp.begin(), dp.end());
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
