#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
vector<vector<int> > t;
vector<int> color;
void dfs(int v){
	for(auto c : t[v]){
		dfs(c);
		color[v] += color[c];
	}
}
void solve(){
	int n;
	cin >> n;
	t.clear();
	t.resize(n);
	color.clear(), color.resize(n);
	for(int i = 0; i < n - 1; ++i){
		int p;
		cin >> p;
		--p;
		t[p].push_back(i + 1);
	}
	for(int i = 0; i < n; ++i){
		char c;
		cin >> c;
		if(c == 'W')
			color[i] = 1;
		else
			color[i] = -1;
	}
	dfs(0);
	int ans = 0;
	for(int i = 0; i < n; ++i){
		ans += (color[i] == 0);
	}
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
}