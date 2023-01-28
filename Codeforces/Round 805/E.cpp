#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<vector<int> > graph(n), num(n);
	bool flag = 1;
	for(int i = 0; i < n; ++i){
		int a, b;
		cin >> a >> b;
		--a, --b;
		if(a == b){
			flag = 0;
			continue ;
		}
		num[a].push_back(i);
		num[b].push_back(i);
	}
	if(flag == 0){
		cout << "NO\n";
		return ;
	}
	for(int i = 0; i < n; ++i){
		if(num[i].size() > 2){
			cout << "NO\n";
			return ;
		}
	}
	for(int i = 0; i < n; ++i){
		if(num[i].size() == 2){
			int a = num[i][0], b = num[i][1];
			graph[a].push_back(b), graph[b].push_back(a);
		}
	}
	vector<int> col(n, -1);
	auto bfs = [&](int u){
		int cur = 1;
		vector<int> v;
		v.push_back(u);
		while(v.size()){
			for(auto c : v){
				if(col[c] != -1 && col[c] != cur){
					return 0;
				}
				col[c] = cur;
			}
			cur ^= 1;
			vector<int> tmp = v;
			v.clear();
			for(auto c : tmp){
				for(auto t : graph[c]){
					if(col[t] == -1){
						v.push_back(t);
					}else if(col[t] != cur){
						return 0;
					}
				}
			}
		}
		return 1;
	};
	for(int i = 0; i < n; ++i){
		if(col[i] == -1){
			if(!bfs(i)){
				cout << "NO\n";
				return ;
			}
		}
	}
	cout << "YES\n";
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