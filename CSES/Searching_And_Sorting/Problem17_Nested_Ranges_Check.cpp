#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
int main(){
	int n;
	cin >> n;
	vector<tuple<int, int, int> > v(n + 1);
	vector<bool> vis(n + 2);
	for(int i = 1; i <= n; ++i){
		int x, y;
		cin >> x >> y;
		v[i] = {x, y, i};
	}
	sort(v.begin(), v.end());
	vector<int> preR(n + 2), sufL(n + 2, INF);
	// preR[i] = max value of R, from 1 to i
	// sufL[i] = min value of L, from i to n
	for(int i = 1; i <= n; ++i){
		int l, r, ind;
		tie(l, r, ind) = v[i];
		preR[i] = max(preR[i - 1], r);
	}
	for(int i = n; i > 0; --i){
		int l, r, ind;
		tie(l, r, ind) = v[i];
		sufL[i] = min(sufL[i + 1], l);
	}
	for(int i = 1; i <= n; ++i){
		int l, r, ind;
		tie(l, r, ind) = v[i];
		if(l <= preR[i] || r >= sufL[i]){
			vis[ind] = 1;
		}
	}
	for(int i = 1; i <= n; ++i){
		cout << vis[i] << ' ';
	}
	cout << '\n';
}