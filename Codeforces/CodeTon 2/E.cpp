#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<vector<int> > graph(n);
	vector<int> in(n);
	for(int i = 0; i < m; ++i){
		int x, y;
		cin >> x >> y;
		--x, --y;
		++in[y];
		graph[x].push_back(y);
	}

	queue<int> q;
	for(int i = 0; i < n; ++i){
		if(in[i] == 0){
			q.push(i);
		}
	}
	vector<int> d;
	while(q.size()){
		int u = q.front();
		q.pop();
		d.push_back(u);
		for(auto v : graph[u]){
			--in[v];
			if(in[v] == 0){
				q.push(v);
			}
		}
	}

	ll cnt = 0;

	for(int i = 0; i < n - 1; ++i){
		bool flag = 0;
		for(int j = n - 1; j > -1; --j){
			if(a[d[j]] > 0){
				flag = 1;
				--a[d[j]];
				for(auto v : graph[d[j]]){
					++a[v];
				}
			}
		}
		cnt += flag ;
	}

	for(int i = 0; i < n; ++i){
		for(auto v : graph[d[i]]){
			a[v] += a[d[i]];
			a[v] %= MOD;
		}
	}

	cout << (cnt + a[d[n - 1]]) % MOD << '\n';
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