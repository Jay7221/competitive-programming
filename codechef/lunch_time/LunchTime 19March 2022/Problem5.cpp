#include<bits/stdc++.h>
using namespace std;
const int nmax = 3e5 + 5;
#define vi vector<int>
vi g[nmax];
int frozen[nmax];
queue<pair<int, int> > que;

int currenttime;

static void timepass(){
while(!que.empty()){
	int t, x;
	tie(t, x) = que.front();
	if(t > currenttime)
		break ;
	que.pop();
	for(auto y : g[x]){
		if(frozen[y])
			continue ;
		que.push({t + 1, y});
		frozen[y] = 1;
	}
}
currenttime++;
}
void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 0, x, y; i < m; i++){
		cin >> x >> y;
		--x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 0; i < q; i++){
		int t, x;
		cin >> t >> x;
		if(t == 1){
			--x;
			if(frozen[x] == 0){
				frozen[x] = 1;
				que.push({currenttime, x});
			}
		}
		if(t == 2){
			x = min(n + 1, x + currenttime);
			while(x > currenttime){
				timepass();
			}
		}
		if(t == 3){
			--x;
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