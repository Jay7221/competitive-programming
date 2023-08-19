#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vb vector<bool>
const int max_s = 3e5 + 5;
vi g[max_s];
vb frozen(max_s + 1, 0);
stack<int> frozen_n;
int curtime = 1;
void timepass(){
	curtime++;
	stack<int> other;
	while(!frozen_n.empty()){
		int a = frozen_n.top();
		frozen_n.pop();
		for(auto c : g[a]){
			if(!frozen[c]){
				frozen[c] = 1;
				other.push(c);
			}
		}
	}
	frozen_n = other;
}
void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 0; i < q; i++){
		int t, x;
		cin >> t >> x;
		if(t == 1){
			if(frozen[x] == 0){
				frozen[x] = 1;
				frozen_n.push(x);
			}
		}
		if(t == 2){
			while(x--){
				timepass();
				if(curtime > n - 1)
					break ;
			}
		}
		if(t == 3){
			cout << (frozen[x] ? "YES\n" : "NO\n");
		}
	}

}
int main(){
	int t;
	t = 1;
	while(t--){
		solve();
	}
}