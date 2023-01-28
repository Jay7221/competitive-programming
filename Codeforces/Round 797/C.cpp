#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> s(n), f(n), d(n);
	for(int i = 0; i < n; ++i){
		cin >> s[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> f[i];
	}
	d[0] = f[0] - s[0];
	for(int i = 1; i < n; ++i){
		d[i] = min(f[i] - s[i], f[i] - f[i - 1]);
	}
	for(auto dur : d)
		cout << dur << ' ';
	cout << '\n';
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
