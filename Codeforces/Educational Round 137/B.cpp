#include<iostream>
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i){
		a[i] = i + 1;
	}
	if(n > 1){
		a[1] = a[n - 1];
		a[n - 1] = 2;
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