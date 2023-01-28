#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j)
			cin >> a[i][j];
	}
	int x = -1, y = -1;
	for(int i = 0; i < n; ++i){
		if(x != -1){
			break ;
		}
		vector<int> tmp = a[i];
		sort(tmp.begin(), tmp.end());
		for(int j = 0; j < m; ++j){
			if(a[i][j] != tmp[j]){
				if(x == -1){
					 x = j;
				}else if(y == -1){
					y = j;
				}else{
					cout << -1 << '\n';
					return ;
				}
			}
		}
	}
	if(x == -1 && y == -1){
		cout << 1 << ' ' << 1 << '\n';
		return ;
	}
	for(int i = 0; i < n; ++i){
		swap(a[i][x], a[i][y]);
		if(is_sorted(a[i].begin(), a[i].end()))
			continue ;
		cout << -1 << '\n';
		return ;
	}
	cout << x + 1 << ' ' << y + 1 << '\n';
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