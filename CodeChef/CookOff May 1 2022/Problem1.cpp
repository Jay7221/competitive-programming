#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for(int i = n - 1; i > 0; i--){
		a[i] = a[i] - a[i - 1];
	}
	for(int i = 1; i < n - 1; i++){
		if((a[i] == a[i + 1] * 2) || (a[i + 1] == a[i] * 2))
			continue ;
		cout << "NO\n";
		return ;
	}
	cout << "YES\n";
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