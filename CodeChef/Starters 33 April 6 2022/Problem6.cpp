#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	debug(a)
	debug(b)
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
	#endif
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}