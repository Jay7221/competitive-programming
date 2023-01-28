#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, x;
	cin >> n >> x;
	map<int, vector<int> > freq;
	vector<pair<int, int> > ans;
	for(int i = 1; i < n + 1; i++){
		// cerr << i << '\n';
		int a;
		cin >> a;
		if(a > x)
			continue ;
		if(ans.size())
			continue ;
		for(auto c : freq[x - a]){
			ans.push_back({c, i});
		}
		freq[a].push_back(i);
	}
	if(ans.empty()){
		cout << "IMPOSSIBLE";
	}else{
		cout << ans[0].first << ' ' << ans[0].second << '\n';
	}
}