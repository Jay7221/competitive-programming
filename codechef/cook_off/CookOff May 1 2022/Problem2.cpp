#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	vector<vector<int> > next(6);
	vector<vector<bool> > states(n, vector<bool>(6, 0));
	next[0] = {0, 1, 4};
	next[1] = {2, 3, 5};
	next[2] = {0, 1, 4};
	next[3] = {0, 1, 4};
	next[4] = {2, 3, 5};
	next[5] = {2, 3, 5};
	vector<int> f(6);
	f[0] = 0, f[1] = 1, f[2] = 1, f[3] = 2, f[4] = 2, f[5] = 3;
	for(int i = 0; i  < 6; i++){
		if(f[i] == a[0]){
			states[0][i] = 1;
		}
	}
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < 6; j++){
			if(!states[i][j]){
				continue ;
			}
			for(auto c : next[j]){
				if(f[c] == a[i + 1]){
					states[i + 1][c] = 1;
				}
			}
		}
	}
	for(auto c : states){
		for(auto k : c)
			cerr << k << ' ' ;
		cerr << '\n';
	}
	cerr << '\n';
	for(int i = 0; i < 6; i++){
		if(states[n - 1][i]){
			cout << "YES\n";
			return ;
		}
	}
	cout << "NO\n";
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