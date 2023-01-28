#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define debug(a, n) for(int i = 0; i < n; i++){cerr << a[i] << ' ';} cerr << '\n';
void solve(){

}
bool is_interesting(int n){
	ll prod = 1;
	ll sum = 0;
	int t;
	while(n > 0){
		t = n % 10;
		n /= 10;
		prod *= t;
		sum += t;
	}
	bool ans = 1;
	if(prod % sum)	ans = 0;
	return ans;
}
int main(){
	// int t;
	// cin >> t;
	// for(int i = 1; i <= t; i++){
	// 	cout << "Case #" << i << ": ";
	// 	solve();
	// }
	for(int i = 10; i < 1000; i++){
		if(is_interesting(i)){
			cout << i << '\n';
		}
	}
}