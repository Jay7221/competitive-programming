#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
bool is_prime(int n){
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0)
			return 0;
	}
	return 1;
}
void solve(){
	int n;
	cin >> n;
	if(n == 1){
		cout << 1 << '\n';
		return ;
	}
	if(n == 2){
		cout << 2 << '\n';
		return ;
	}
	if(is_prime(n)){
		cout << 3 << '\n';
	}else{
		cout << 2 << '\n';
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
}