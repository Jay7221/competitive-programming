#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	if(k == 1){
		cout << ((n - 1) / 2) << '\n';
		return ;
	}
	int ans = 0;
	for(int i = 1; i < n - 1; ++i){
		if(a[i] > a[i - 1] + a[i + 1]){
			++ans;
		}
	}
	cout << ans << '\n';

}
int main(){
	// freopen("inputf.in","r",stdin);
	// freopen("outputf.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}