#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(int i = 0; i < a.size(); i++){cerr << i << " : " ;for(auto c : a[i]){cerr << c << ' ' ;} cerr << '\n';} cerr << '\n';
bool bfs(int cur){
	
}
void solve(){
	int n;
	cin >> n;
	vector<int> left(n), right(n);
	unordered_map<int, vector<int> > speeds;
	// speeds[i] stores the indexes of lines travelling at speed vi
	for(int i = 0; i < n; i++){
		cin >> left[i] >> right[i] ;
		int v;
		cin >> v;
		speeds[v].push_back(i);
	}
	vector<vector<int> > tree(n);
	for(auto v : speeds){
		vector<int> arr = v.second;
		for(auto cur : arr){
			for(auto other : arr){
				if(cur == other)
					continue ;
				if(left[cur] <= left[other] && left[other] <= right[cur])
					tree[cur].push_back(other);
				else if(right[cur] >= right[other] && left[cur] <= right[other])
					tree[cur].push_back(other);
			}
		}
	}
	debug(tree)
	// cerr << "od" << '\n';
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
	#endif
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}