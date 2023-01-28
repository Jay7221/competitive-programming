#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n), d(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	vector<pair<int, int> > arr(n);
	for(int i = 0; i < n; ++i)
		arr[i] = {a[i], b[i]};
	sort(arr.begin(), arr.end());
	for(int i = 0; i < n; ++i){
		c[i] = arr[i].first, d[i] = arr[i].second;
	}
	if(!is_sorted(c.begin(), c.end()) || !is_sorted(d.begin(), d.end())){
		cout << -1 << '\n';
		return ;
	}
	vector<pair<int, int> > p(n);
	for(int i = 0; i < n; ++i){
		p[i] = {a[i], b[i]};
	}
	vector<pair<int, int> > ans;
	for(int i = 0; i < n; ++i){
		int ind = i;
		for(int j = i + 1; j < n; ++j){
			if(p[ind] > p[j])
				ind = j;
		}
		if(ind != i){
			ans.push_back({i, ind});
			swap(p[i], p[ind]);
		}
	}
	cout << ans.size() << '\n';
	for(auto c : ans){
		cout << c.first + 1 << ' ' << c.second + 1 << '\n';
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