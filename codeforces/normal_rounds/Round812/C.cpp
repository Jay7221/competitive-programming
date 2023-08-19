#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<int> squares;
	vector<int> vis(n);
	vector<int> ans(n);
	for(int i = 0; i * i < 2 * n - 1; ++i){
		squares.push_back(i * i);
	}
	bool flag = 1;
	for(int i = n - 1; i > -1; --i){
		bool tmp_flag = 0;
		for(int j = squares.size() - 1; j > -1; --j){
			int k = squares[j] - i;
			if(k < n && !vis[k]){
				vis[k] = 1;
				ans[i] = k;
				tmp_flag = 1;
				break ;
			}
		}
		if(!tmp_flag){
			flag = 0;
		}
	}
	vector<int> b = ans;
	sort(b.begin(), b.end());
	for(int i = 0; i < n; ++i){
		if(b[i] != i){
			flag = 0;
			break ;
		}
	}
	if(flag){
		for(auto c : ans)
			cout << c << ' ';
		cout << '\n';
	}else{
		cout << -1 << '\n';
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}