#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<vector<int> > colors(n);
	for(int i = 0; i < n; ++i){
		int c;
		cin >> c;
		--c;
		colors[c].push_back(i);
	}
	vector<int> ans(n);
	for(int i = 0; i < n; ++i){
		int oddans = 0, evenans = 0;
		for(auto ind : colors[i]){
			if(ind % 2){
				oddans = max(oddans, evenans + 1);
			}else{
				evenans = max(evenans, oddans + 1);
			}
		}
		ans[i] = max(evenans, oddans);
	}
	for(auto c : ans){
		cout << c << ' ';
	}
	cout << '\n';
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