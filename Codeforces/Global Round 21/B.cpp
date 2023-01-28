#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >>  n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(a[i] == 0)
			continue ;
		++ans;
		while((i + 1 < n) && (a[i + 1] > 0))
			++i;
	}
	cout << min(ans, 2) << '\n';
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