#include<iostream>
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	int x = (n / 2) + (n % 2), y = n;
	for(int i = 0; i < n; i += 2){
		a[i] = x;
		a[i + 1] = y;
		--x;
		--y;
	}
	if(n % 2){
		a[n - 1] = 1;
	}
	for(int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	cout << '\n';
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