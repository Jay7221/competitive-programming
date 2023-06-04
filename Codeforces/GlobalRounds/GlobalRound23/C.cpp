#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = n; i > 0; --i)
		a[i] = a[i] - a[i - 1];
	vector<pair<int, int> > v;
	for(int i = 1; i <= n; ++i)
		v.push_back({a[i], i});
	sort(v.rbegin(), v.rend());
	vector<int> ans(n);
	for(int i = 0; i < n; ++i){
		ans[i] = v[i].second;
	}
	for(auto elem : ans)
		cout << elem << ' ' ;
	cout << '\n';
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