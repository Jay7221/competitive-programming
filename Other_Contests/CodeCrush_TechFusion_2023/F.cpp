#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool solve(){
	int n, m, k;
	cin >> n >> m >> k;
	map<pair<int, int>, int> val;
	map<pair<int, int>, bool> vis;
	stack<pair<int, int>> st;
	for(int i = 0; i < k; ++i){
		int a, b;
		cin >> a >> b;
		st.push({a, b});
		int x;
		cin >> x;
		val[{a, b}] = x;
		vis[{a, b}] = true;
	}
	vector<tuple<int, int, int, int, int, int, int, int>> v =
	{
		{-1, -1, -1, 0, 0, -1, 0, 0},
		{-1, 0, -1, 1, 0, 0, 0, 1},
		{0, -1, 0, 0, 1, -1, 1, 0},
		{0, 0, 0, 1, 1, 0, 1, 1}
	};
	auto check = [&](int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
		// cerr << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << '\n';
		if(vis[{x1, y1}] && vis[{x2, y2}] && vis[{x3, y3}] && vis[{x4, y4}]){
			return (val[{x1, y1}] + val[{x4, y4}] == val[{x2, y2}] + val[{x3, y3}]);
		}
		if(vis[{x2, y2}] && vis[{x3, y3}] && vis[{x4, y4}]){
			val[{x1, y1}] = val[{x2, y2}] + val[{x3, y3}] - val[{x4, y4}];
			if(val[{x1, y1}] < 0){
				return false;
			}
			vis[{x1, y1}] = true;
			st.push({x1, y1});
			return true;
		}
		if(vis[{x1, y1}] && vis[{x3, y3}] && vis[{x4, y4}]){
			val[{x2, y2}] = val[{x1, y1}] + val[{x4, y4}] - val[{x3, y3}];
			if(val[{x2, y2}] < 0){
				return false;
			}
			vis[{x2, y2}] = true;
			st.push({x2, y2});
			return true;
		}
		if(vis[{x1, y1}] && vis[{x2, y2}] && vis[{x4, y4}]){
			val[{x3, y3}] = val[{x1, y1}] + val[{x4, y4}] - val[{x2, y2}];
			if(val[{x3, y3}] < 0){
				return false;
			}
			st.push({x3, y3});
			vis[{x3, y3}] = true;
			return true;
		}
		if(vis[{x1, y1}] && vis[{x2, y2}] && vis[{x3, y3}]){
			val[{x4, y4}] = val[{x2, y2}] + val[{x3, y3}] - val[{x1, y1}];
			if(val[{x4, y4}] < 0){
				return false;
			}
			st.push({x4, y4});
			vis[{x4, y4}] = true;
			return true;
		}
		return true;
	};
	auto checkxy = [&](int x, int y){
		for(auto d : v){
			int dx1, dy1, dx2, dy2, dx3, dy3, dx4, dy4;
			tie(dx1, dy1, dx2, dy2, dx3, dy3, dx4, dy4) = d;
			int xx1 = x + dx1;
			int yy1 = y + dy1;
			int xx2 = x + dx2;
			int yy2 = y + dy2;
			int xx3 = x + dx3;
			int yy3 = y + dy3;
			int xx4 = x + dx4;
			int yy4 = y + dy4;
			if(!check(xx1, yy1, xx2, yy2, xx3, yy3, xx4, yy4)){
				return false;
			}
		}
		return true;
	};
	while(st.size()){
		int a, b;
		tie(a, b) = st.top();
		st.pop();
		// cerr << a << ' ' << b << ' ' << val[{a, b}] << '\n';
		if(!checkxy(a, b)){
			return false;
		}
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(solve()){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}

	return 0;
}
