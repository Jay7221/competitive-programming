#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, k, r, c;
	cin >> n  >> k >> r >> c;
	--r, --c;
	vector<vector<char> > a(n, vector<char>(n, '.'));
	vector<int> coords;
	int cur = c;
	while(coords.size() < n / k){
		coords.push_back(cur);
		cur = (cur + k) % n;
	}
	cur = r;
	int cnt = n;
	while(cnt--){
		for(auto &elem : coords){
			a[cur][elem] = 'X';
			elem = (elem + 1) % n;
		}
		cur = (cur + 1) % n;
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << a[i][j];
		}
		cout << '\n';
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}