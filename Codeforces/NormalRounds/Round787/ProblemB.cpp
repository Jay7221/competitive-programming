#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = n - 1; i > 0; i--){
		if(a[i] == 0){
			cout << -1 << '\n';
			return ;
		}
		while(a[i - 1] >= a[i]){
			ans++;
			a[i - 1] /= 2;
		}
	}
	cout << ans << '\n';
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