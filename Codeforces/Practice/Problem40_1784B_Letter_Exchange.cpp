#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> graph[3][3];
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			graph[i][j] = vector<int>();
		}
	}
	for(int i = 1; i <= n; ++i){
		string s;
		cin >> s;
		int a = 0, b = 0, c = 0;
		for(char ch : s){
			if(ch == 'w'){
				++a;
			}
			else if(ch == 'i'){
				++b;
			}
			else{
				++c;
			}
		}
		if(a > 1){
			if(b < 1){
				graph[0][1].push_back(i);
			}
			if(c < 1){
				graph[0][2].push_back(i);
			}
		}
		else if(b > 1){
			if(a < 1){
				graph[1][0].push_back(i);
			}
			if(c < 1){
				graph[1][2].push_back(i);
			}
		}
		else if(c > 1){
			if(a < 1){
				graph[2][0].push_back(i);
			}
			if(b < 1){
				graph[2][1].push_back(i);
			}
		}
	}
	auto getChar = [&](int ind){
		if(ind == 0){
			return 'w';
		}else if(ind == 1){
			return 'i';
		}
		return 'n';
	};
	vector<tuple<int, char, int, char>> ans;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			while((graph[i][j].size()) && (graph[j][i].size())){
				int c1 = graph[i][j].back();
				int c2 = graph[j][i].back();
				graph[i][j].pop_back();
				graph[j][i].pop_back();
				ans.push_back({c1, getChar(i), c2, getChar(j)});
			}
		}
	}
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			for(int k = 0; k < 3; ++k){
				while(graph[i][j].size() && graph[j][k].size() && graph[k][i].size()){
					int c1 = graph[i][j].back();
					graph[i][j].pop_back();

					int c2 = graph[j][k].back();
					graph[j][k].pop_back();
					
					int c3 = graph[k][i].back();
					graph[k][i].pop_back();
					
					ans.push_back({c1, getChar(i), c2, getChar(j)});
					ans.push_back({c2, getChar(i), c3, getChar(k)});
				}
			}
		}
	}
	cout << ans.size() << '\n';
	for(auto [u, v, w, x] : ans){
		cout << u << ' ' << v << ' ' << w << ' ' << x << '\n';
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
	return 0;
}
