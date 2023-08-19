#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
class LockedBoxes{
public:
	vector<int> openAll(int n, vector<int> box, vector<int> key){
		vector<int> in(n);
		vector<bool> vis(n);
		vector<vector<int> > graph(n);
		for(int i = 0; i < n; ++i){
			int u = box[i], v = key[i];
			if(u != v){
				graph[u].push_back(v);
				++in[v];
			}
		}
		int cur = 0;
		set<int> s;
		for(int i = 0; i < n; ++i)
			s.insert(i);
		vector<int> ans;
		auto bfs = [&](int node){
			queue<int> q;
			q.push(node);
			ans.push_back(node);
			while(q.size()){
				int u = q.front();
				s.erase(u);
				vis[u] = 1;
				q.pop();
				for(auto c : graph[u]){
					if(vis[c])
						continue ;
					--in[c];
					q.push(c);
				}
			}
		};
		for(int i = 0; i < n; ++i){
			if(!vis[i] && in[i] == 0){
				bfs(i);
			}
		}
		for(int i = 0; i < n; ++i){
			if(!vis[i])
				bfs(i);
		}
		return ans;
	}
};
int main(){
	LockedBoxes l;
	vector<int> a = {0, 1, 2}, b = {1, 2, 0};
}