#include<iostream>
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n / 2; ++i)
		a[i] = a[n - 1 - i] - a[i];
	int ans = a[0];
	for(int i = 0; i < n / 2; ++i){
		if(a[i] < 0)
			ans = -1;
	}
	for(int i = 1; i < n / 2; ++i){
		if(a[i - 1] < a[i]){
			ans = -1;
		}
	}
	cout << ans << '\n';
	return ;
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
	return 0;
}
