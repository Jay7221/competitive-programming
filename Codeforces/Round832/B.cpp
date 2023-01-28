#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<pair<int, int> > v;
	int i = 1, j = 3 * n - 1;
	while(i < j){
		v.push_back({i, j});
		i += 3;
		j -= 3;
	}
	cout << v.size() << '\n';
	for(auto [l, r] : v)
		cout << l << ' ' << r << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}