#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<vector<char>> v(4 * n, vector<char>(4 * n, ' '));
	for(int i = n; i < 2 * n; ++i){
		v[i][n - 1] = '|';
	}
	auto start_down = [&](int l, int r){
		int k = 1;
		for(int i = l; i < l + n; ++i){
			int cnt = k;
			for(int j = r; j < r + n; ++j){
				if(cnt > 0){
					v[i][j] = '*';
				}
				--cnt;
			}
			++k;
		}
		for(int i = l + n; i < l + 2 * n - 1; ++i){
			
		}
	};
	start_down(0, 0);
	auto print = [&](){
		for(auto vv : v){
			for(char ch : vv){
				cout << ch;
			}
			cout << '\n';
		}
	};
	print();
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}
