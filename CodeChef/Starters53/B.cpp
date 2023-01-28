#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c.first << ' ' << c.second << '\n' ; } cerr << "------------------\n";
void solve(){
	int x, y;
	cin >> x >> y;
	vector<vector<int> > board(9, vector<int>(9));
	board[x][y] = 1;
	auto check = [&](int x, int y){
		if((x < 1) || (y < 1) || (x > 8) || (y > 8))
			return 0;
		return 1;
	};
	pair<int, int> king = {x, y};
	auto attack = [&](pair<int, int> p, pair<int, int> q){
		int x, y, a, b;
		tie(x, y) = p;
		tie(a, b) = q;
		if((x == a) || (y == b)){
			return 1;
		}
		if(abs(x - a) == abs(y - b))
			return 1;
		return 0;
	};
	vector<pair<int, int> > nei;
	for(int i = 1; i >= -1; --i){
		for(int j = -1; j < 2; ++j){
			if(i == 0 && j == 0)
				continue ;
			if(check(x + i, y + j))
				nei.push_back({x + i, y + j});
		}
	}
	bool cont = 1;
	for(int i = 1; i < 9 && cont; ++i){
		for(int j = 1; j < 9 && cont; ++j){
			pair<int, int> cur = {i, j};
			if(attack(cur, king))
				continue;
			bool flag = 0;
			for(auto p : nei){
				if(!attack(cur, p))
					flag = 0;
			}
			if(flag == 1){
				board[i][j] = 2;
				cont = 0;
			}
		}
	}
	if(cont){
		for(int i = 1; i < 9 && cont; ++i){
			for(int j = 1; j < 9 && cont; ++j){
				for(int a = 1; a < 9 && cont; ++a){
					for(int b = 1; b < 9 && cont; ++b){
						pair<int, int> cur1 = {i, j}, cur2 = {a, b};
						if(attack(king, cur1) || attack(king, cur2))
							continue ;
						bool flag = 1;
						for(auto c : nei){
							if(!attack(cur1, c) && !attack(cur2, c))
								flag = 0;
						}
						if(flag){
							board[i][j] = 2;
							board[a][b] = 2;
							cont = 0;
						}
					}
				}
			}
		}
	}
	for(int i = 1; i < 9; ++i){
		for(int j = 1; j <9; ++j)
			cout << board[i][j] << ' ' ;
		cout << '\n';
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}