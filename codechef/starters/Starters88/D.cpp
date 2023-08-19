#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	map<int, vector<pair<int, int> >> pairs;
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			pairs[a[i] + a[j]].push_back({j, i});
		}
	}
	int ans = n;
	for(auto [u, v] : pairs){
		int tmp = n;
		sort(v.begin(), v.end());
		int R = -1;
		for(auto [r, l] : v){
			if(l > R){
				tmp -= 2;
				R = r;
			}
		}
		ans = min(ans, tmp);
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