#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, k;
	cin >> n >> k;
	ll x = 0, y = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		x += a, y += a * a;
	}
	// cerr << x << ' '  << y << '\n';
	if(x == 0){
		if(y == 0)
			cout << 0 << '\n';
		else
			cout << "IMPOSSIBLE\n";
		return ;
	}
	if((y - x * x) % (2 * x) == 0){
		cout << (y - x * x) / (2 * x) << '\n';
	}else{
		cout << "IMPOSSIBLE\n";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i  < t + 1; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
}