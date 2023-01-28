#include<bits/stdc++.h>
using namespace std;
#define inf (int)(1e9 + 7)
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > graph(n, vector<int>(m, inf));
	int s_i, s_j;
	vector<pair<int, int> > d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	map<pair<int, int>, char> mp;
	mp[{0, 1}] = 'R';
	mp[{0, -1}] = 'L';
	mp[{1, 0}] = 'D';
	mp[{-1, 0}] = 'U';
	auto bfs = [&](queue<pair<int, int> > proc){
		queue<pair<int, int> > next = proc;
		while(!next.empty()){
			int i, j;
			tie(i, j) = next.front();
			next.pop();
			for(auto c : d){
				int dx, dy;
				tie(dx, dy) = c;
				int x = i + dx, y = j + dy;
				if(x > -1 && x < n && y > -1 && y < m){
					if(graph[x][y] > graph[i][j] + 1){
						graph[x][y] = graph[i][j] + 1;
						next.push({x, y});
					}
				}
			}
		}
	};
	int a_i, a_j;
	vector<vector<char> > path(n, vector<char>(m));
	auto path_find = [&](){
		queue<pair<int, int> > next;
		next.push({s_i, s_j});
		int step = 1;
		while(!next.empty()){
			int s = next.size();
			while(s--){
				int i, j;
				tie(i, j) = next.front();
				next.pop();
				for(auto c : d){
					int dx, dy;
					tie(dx, dy) = c;
					int x = i + dx, y = j + dy;
					if(x < 0 || y < 0 || x > n - 1 || y > m - 1){
						a_i = i, a_j = j;
						return 1;
					}
					if(graph[x][y] > step){
						next.push({x, y});
						graph[x][y] = step;
						path[x][y] = mp[c];
					}
				}
			}
			step++;
		}
		return 0;
	};
	queue<pair<int, int> > proc;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			if(c == '#')
				graph[i][j] = 0;
			if(c == 'M'){
				graph[i][j] = 0;
				proc.push({i, j});
			}
			if(c == 'A')
				s_i = i, s_j = j;
		}
	}
	bfs(proc);
	if(!path_find()){
		cout << "NO";
		return ;
	}
	cout << "YES\n";
	stack<char> ans;
	int i = a_i, j = a_j;
	while(i != s_i || j != s_j){
		ans.push(path[i][j]);
		switch(path[i][j]){
			case 'L':
				j++;
				break ;
			case 'R':
				j--;
				break ;
			case 'U':
				i++;
				break ;
			case 'D':
				i--;
				break ;
		}
	}
	cout << ans.size() << '\n';
	while(ans.size()){
		cout << ans.top();
		ans.pop();
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}