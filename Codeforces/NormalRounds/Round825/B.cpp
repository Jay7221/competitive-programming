#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	int b[n + 1];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	b[0] = a[0], b[n] = a[n - 1];
	for(int i = 1; i < n; ++i){
		b[i] = lcm(a[i], a[i - 1]);
	}
	bool flag = true;
	for(int i = 0; i < n; ++i){
		if(a[i] != gcd(b[i], b[i + 1])){
			flag = false;
			break ;
		}
	}
	if(flag)
		cout << "YES\n";
	else
		cout << "NO\n";
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