#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, q;
	cin >> n >> q;
	set<int> x_r, y_r;
	multiset<int> x_rook, y_rook;
	set<int> x_not, y_not;
	for(int i = 1; i < n + 1; ++i)
		x_not.insert(i), y_not.insert(i);
	auto debug = [&](set<int> s){
		for(auto c : s)
			cerr << c << ' ' ;
		cerr << '\n';
	};
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int x, y;
			cin >> x >> y;
			x_rook.insert(x), y_rook.insert(y);
			x_not.erase(x),y_not.erase(y);
		}else if(t == 2){
			int x, y;
			cin >> x >> y;
			x_rook.erase(x_rook.find(x)), y_rook.erase(y_rook.find(y));
			if(x_rook.find(x) == x_rook.end())
				x_not.insert(x);
			if(y_rook.find(y) == y_rook.end())
				y_not.insert(y);
		}else{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			bool attacked = 1, atx = 1, aty = 1;
			auto it = x_not.lower_bound(x1);
			if(it != x_not.end() && *it <= x2)
				atx = 0;
			it = y_not.lower_bound(y1);
			if(it != y_not.end() && *it <= y2)
				aty = 0;
			attacked = atx || aty;
			if(attacked)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}