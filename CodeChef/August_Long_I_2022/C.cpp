#include<bits/stdc++.h>
using namespace std;
#define sort(a) sort(a.begin(), a.end());
#define debug(a) for(auto c : a){cerr << c << ' ' ; } cerr << '\n';
#define ll long long
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > A(n, vector<int>(m)), B(n, vector<int>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> A[i][j];
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> B[i][j];
		}
	}
	if(min(m, n) < 2){
		if(A == B){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
		return ;
	}
	map<ll, ll> freq1, freq2;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if((i + j) % 2){
				++freq1[A[i][j]];
				--freq1[B[i][j]];
			}else{
				++freq2[A[i][j]];
				--freq2[B[i][j]];
			}
		}
	}
	bool flag = 1;
	for(auto c : freq1){
		if(c.second != 0){
			cerr << c.first << ' ' << c.second << '\n';
			flag = 0;
			break ;
		}
	}
	for(auto c : freq2){
		if(c.second != 0){
			cerr << c.first << ' ' << c.second << '\n';
			flag = 0;
			break ;
		}
	}
	if(flag)
		cout << "YES\n";
	else
		cout << "NO\n";
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}