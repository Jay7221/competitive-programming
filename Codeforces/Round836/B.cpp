#include<iostream>
using namespace std;
void solve(){
	int n;
	cin >> n;
	if(n % 2){
		for(int i = 0; i < n; ++i)
			cout << 1 << ' ';
		cout << '\n';
	}else{
		cout << 1 << ' ' << 3 << ' ';
		for(int i = 2; i < n; ++i)
			cout << 2 << ' ' ;
		cout <<'\n';
	}
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