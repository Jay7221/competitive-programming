#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, m, x;
	cin >> n >> m >> x;
	if(x == m){
		cout << 0 << '\n';
		return ;
	}
	cout << (x * n) / (x + 1) << '\n';
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