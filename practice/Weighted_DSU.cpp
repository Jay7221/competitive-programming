#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
struct DSU{
	int n;
	vector<pair<int, int> > par;
	vector<int> rank;
public:
	DSU(int sz){
		n = sz;
		par.resize(n);
		rank.resize(n);
		for(int i = 0; i < n; ++i){
			par[i] = {i, 0};
			rank[i] = 1;
		}
	}
	pair<int, int> find(int a){
		int p, c;
		tie(p, c) = find(par[a].first);
		if(p == a && c == 0)
			return par[a];
		par[a] = {p, (c + par[a].second) % 3};
		return par[a];
	}
	bool merge(int u, int v, int c){
		int p1, p2, c1, c2;
		tie(p1, c1) = find(u);
		tie(p2, c2) = find(v);
		if(p1 == p2){
			if((c1 + c2) % 3 == 0){
				return 1;
			}else{
				return 0;
			}
		}
		if(rank[p1] < rank[p2]){
			swap(p1, p2);
			swap(c1, c2);
		}
		rank[p1] += rank[p2];
		par[p2] = {p1, c + c2 - c1};
		return 1;
	}
};
void solve(){
	int n, k;
	cin >> n >> k;
	int ans = 0;
	DSU data(n);
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