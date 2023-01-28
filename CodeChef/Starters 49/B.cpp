#include<bits/stdc++.h>
using namespace std;
void solve(){
	auto debug = [&](vector<int>& a){
		for(auto c : a){
			cerr << c << ' ';
		}
		cerr << '\n';
	};
	int n;
	cin >> n;
	map<int, int> freq;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		++freq[a];
	}
	vector<int> v;
	for(auto c : freq){
		v.push_back(c.second);
	}
	sort(v.rbegin(), v.rend());
	int ans = (v[0] + 1) / 2;
	if(v.size() > 1){
		ans = max(ans, v[1]);
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}