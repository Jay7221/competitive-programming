#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define debug(a, n) for(int i = 0;i < n ;i++){cerr << a[i] << ' ';} cerr << '\n';
void solve(){
	int x;
	cin >> x;
	if(x % 5){
		cout << -1 << '\n';
		return ;
	}
	int ans = 0;
	ans += x / 10;
	ans += (x % 10) / 5;
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}