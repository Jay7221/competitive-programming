#include<iostream>
using namespace std;
void solve(){
	int n;
	cin >> n;
	if(n == 1 || n == 3){
		cout << -1 << '\n';
		return ;
	}
	if(n % 2){
		cout << n - 1 << ' ' << n << ' ' ;
		for(int i = 1; i <= n - 2; ++i)
			cout << i << ' ' ;
		cout << '\n';
	}else{
		for(int i = 1; i <= n; i += 2){
			cout << i + 1 << ' ' << i << ' ';
		}
		cout << '\n';
	}
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