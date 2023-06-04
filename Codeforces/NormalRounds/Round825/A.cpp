#include<iostream>
using namespace std;
void solve(){
	int n;
	cin >> n;
	bool a[n], b[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	int ans1 = 0;
	for(int i = 0; i < n; ++i){
		ans1 += a[i] - b[i];
	}
	ans1 = abs(ans1);
	++ans1;
	int ans2 = 0;
	for(int i = 0; i < n; ++i){
		ans2 += a[i] ^ b[i];
	}
	int finalAns = min(ans1, ans2);
	cout << finalAns << '\n';
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