#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n), d(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int mx = *max_element(a.begin(), a.end());
	for(int i = 0; i < n; ++i){
		d[i] = (mx + i + 1 - a[i]);
	}
	vector<vector<int> > ans(20);
	for(int k = 0; k < 20; ++k){
		for(int i = 0; i < n; ++i){
			if(d[i] & (1 << k)){
				ans[k].push_back(i);
			}
		}
	}
	int p = 0;
	for(int i = 0; i < 20; ++i)
		p += (ans[i].size() > 0);
	cout << p << '\n';
	for(int k = 0; k < 20; ++k){
		if(ans[k].empty())
			continue ;
		cout << ans[k].size() << ' ' << (1 << k) << '\n';
		for(auto c : ans[k])
			cout << c + 1 << ' ';
		cout << '\n';
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