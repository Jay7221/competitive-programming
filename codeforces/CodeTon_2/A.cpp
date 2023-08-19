#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	if(n < m){
		cout << "NO\n";
		return ;
	}
	int i = n - 1, j = m - 1;
	for(; i > -1 && j > -1; --i, --j){
		if(a[i] == b[j])
			continue ;
		else
			break ;
	}
	if(j == -1){
		cout << "YES\n";
		return ;
	}
	if(j > 0){
		cout << "NO\n";
		return ;
	}
	for(int pos = 0; pos < i; ++pos){
		if(a[pos] == b[j]){
			cout << "YES\n";
			return ;
		}
	}
	cout << "NO\n";
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