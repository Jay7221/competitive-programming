#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > graph(n);
	vector<int> in(n), out(n);
	// in[i] = how many nodes point to i
	// out[i] = to how many nodes does i point to
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		graph[a].push_back(b);
		in[b]++, out[a]++;
	}
	int ans = 0;
	queue<int> start, ord;
	for(int i = 0; i < n; i++){
		if(in[i] == 0){
			start.push(i);
		}
		if(out[i] == 0)
			ans++;
	}
	while(!start.empty()){
		int k = start.front();
		ord.push(k);
		start.pop();
		for(auto c : graph[k]){
			in[c]--;
			if(in[c] == 0)
				start.push(c);
		}
	}
	if(ord.size() != n){
		cout << -1 << '\n';
	}else{
		cout << ans - 1 << '\n';
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