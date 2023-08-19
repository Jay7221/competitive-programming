#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
#define ll long long
bool check(vector<int>& a, vector<int>& b){
	int n = a.size(), m = b.size();
	int k = max(a[n - 1], 0);
	if(k > m){
		return 0;
	}
	if(k > 0 && b[k - 1] > 0){
		return 0;
	}
	if(min(b[m - 1], b[m - 1] - n + k) > 0){
		return 0;
	}
	return 1;
}
void solve(){
	ll n, m, c;
	cin >> n >> m >> c;
	vector<int> a(n), b(m);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i] -= c;
	}
	for(int i = 0; i < m; i++){
		cin >> b[i];
		b[i] -= c;
	}
	cerr << '\n';
	if(check(a, b) || check(b, a)){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}