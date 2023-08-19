#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define debug(a, n) for(int i = 0;i < n ;i++){cerr << a[i] << ' ';} cerr << '\n';
void solve(){
	int n, x;
	cin >> n >> x;
	int ans = 0;
	ans += (n / 3) * 2 * x;
	ans += (n % 3) * x;
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}