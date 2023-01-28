#include<bits/stdc++.h>
using namespace std;
bool is_square(int a){
	int t = sqrt(a);
	return t * t == a;
}
int min_sum(int n){
	for(int i = 0; i <= sqrt(n); i++){
		if(is_square(n - i * i)){
			cerr << i << ' ' << sqrt(n - i * i) << '\n';
			return i + sqrt(n - i * i);
		}
	}
}
void solve(){
	int x, y;
	cin >> x >> y;
	int n = x * x + y * y;
	if(n == 0){
		cout << 0 << '\n';
		return ;
	}
	if(is_square(n)){
		cout << 1 << '\n';
		return ;
	}
	cout << 2 << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}