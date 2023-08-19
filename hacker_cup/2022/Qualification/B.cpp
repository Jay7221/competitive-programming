#include<bits/stdc++.h>
using namespace std;
void solve(int t){
	int R, C;
	cin >> R >> C;
	int tree = 0;
	vector<vector<char> > paint(R, vector<char>(C));
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			cin >> paint[i][j];
			tree += (paint[i][j] == '^');
		}
	}
	string ans;
	bool flag = 1;
	if(tree == 0){
		ans = "Possible";
	}else{
		if(R == 1 || C == 1){
			flag = 0;
			ans = "Impossible";
		}else{
			ans = "Possible";
		}
		if(flag){
			for(auto& l : paint){
				for(auto&c : l)
					c = '^';
			}
		}
	}
	cout << "Case #" << t << ": " << ans << "\n";
	if(flag){
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j)
				cout << paint[i][j] ;
			cout << "\n";
		}
	}
}
int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		solve(t);
	}
}