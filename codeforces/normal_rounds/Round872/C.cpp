#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, m;
	cin >> n >> m;
	
	set<int> s;
	int type1 = 0, type2 = 0, type3 = 0;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(x == -1){
			++type1;
		}else if(x == -2){
			++type2;
		}else{
			s.insert(x);
		}
	}
	
	type3 = s.size();
	
	vector<int> x;
	
	x.push_back(0);
	for(int elem : s){
		x.push_back(elem);
	}
	x.push_back(m + 1);
	n = x.size();
	
	vector<int> blocks;
	for(int i = 1; i < n; ++i){
		blocks.push_back(x[i] - x[i - 1] - 1);
	}
	
	n = blocks.size();
	for(int i = 1; i < n; ++i){
		blocks[i] += blocks[i - 1];
	}
	
	int rem = blocks[n - 1];
	
	int ans = min(type2, blocks[n - 1]);
	for(int i = 0; i < n; ++i){
		int tmp = min(type1, blocks[i]) + min(type2, rem - blocks[i]);
		ans = max(ans, tmp);
	}
	ans += type3;
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