#include<iostream>
using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	int d = n, mn = n;
	for(int i = k; i < n; ++i){
		int val = i;
		if((n % i) < k){
			val += (n % i);
		}
		if(val < mn){
			d = i;
			mn = val;
		}
	}
	int a[n];
	for(int i = 0; i < n; ++i){
		a[i] = (i % d) + 1;
	}
	int res = n  - (mn - d)  - 1;
	for(int i = n - 1; i > res; --i){
		a[i] = (i % d) + d + 1;
	}
	cout << mn << '\n';
	for(int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	cout << '\n';
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
	return 0;
}