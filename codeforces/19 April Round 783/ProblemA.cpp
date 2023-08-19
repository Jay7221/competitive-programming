#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, m;
	cin >> n >> m;
	if(n == 1 && m== 1){
		cout << 0 << '\n';
		return ;
	}
	int y = n - 1, x = m - 1;
	if(n == 1 || m == 1){
		if(x > 1 || y > 1){
			cout << -1 << '\n';
		}else{
			cout << max(x, y) << '\n';
		}
		return ;
	}
	int k = abs(x - y);
	if(k == 0){
		cout << x + y << '\n';
		return ;
	}
	k--;
	cout << x + y + k + (k % 2) << '\n';
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