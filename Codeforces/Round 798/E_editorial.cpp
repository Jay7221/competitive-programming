#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define prep(a) a.clear();	a.resize(n);
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
int n;
vector<int> a;
vector<vector<int> > graph(32);
vector<int> vis(32);
void dfs(int u){
	vis[u] = 1;
	for(auto neighbour : graph[u]){
		if(!vis[neighbour])
			dfs(neighbour);
	}
}
bool connected(){
	int m = 0;
	for(int j= 0; j < 31; ++j)
		vis[j] = 0;
	for(int i = 0; i < n; ++i)
		m |= a[i];
	for(int i = 0; i < 31; ++i){
		prep(graph[i])
	}
	for(int i = 0; i < n; ++i){
		int last = -1;
		for(int j = 0; j < 31; ++j){
			if(!(a[i] & (1 << j)))
				continue ;
			if(last == -1){
				last = j;
				continue ;
			}
			graph[last].push_back(j);
			graph[j].push_back(last);
			last = j;
		}
	}
	for(int j = 0; j < 31; ++j){
		if(m & (1 << j)){
			dfs(j);
			break ;
		}
	}
	for(int j = 0; j < 31; ++j){
		if((m & (1 << j)) && (!vis[j])){
			return 0;
		}
	}
	return 1;
}
void solve(){
	cin >> n;
	prep(a)
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(a[i] == 0){
			++ans;
			++a[i];
		}
	}
	auto bin = [&](int n){
		for(int i = 31; i > -1; --i){
			if(n & (1 << i))
				cerr << 1;
			else
				cerr << 0;
		}
		cerr << '\n';
	};
	int m = 0;
	for(int i = 0; i < n; ++i)
		m = max(m, a[i] & -a[i]);
	if(connected()){
		cout << ans << '\n';
		for(int i = 0; i < n; ++i)
			cout << a[i] << ' ';
		cout << '\n';
		return ;
	}
	for(int i = 0; i < n; ++i){
		++a[i];
		if(connected()){
			cout << ans + 1 << '\n';
			for(int i = 0; i < n; ++i)
				cout << a[i] << ' ';
			cout << '\n';
			return ;
		}
		--a[i];
	}
	for(int i = 0; i < n; ++i){
		if(a[i] > 1){
			--a[i];
			if(connected()){
				cout << ans + 1 << '\n';
				for(int i = 0; i < n; ++i)
					cout << a[i] << ' ';
				cout << '\n';
				return ;
			}
			++a[i];
		}
	}
	for(int i = 0; i < n; ++i){
		if((a[i] & -a[i]) == m){
			--a[i];
			++ans ;
			break ;
		}
	}
	if(connected()){
		cout << ans << '\n';
		for(int i = 0; i < n; ++i){
			cout << a[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	for(int i = 0; i < n; ++i){
		if((a[i] & -a[i]) == m){
			++a[i];
			++ans;
			break ;
		}
	}
	cout << ans << '\n';
	for(int i = 0; i < n; ++i){
		cout << a[i] << ' ';
	}
		cout << '\n';
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