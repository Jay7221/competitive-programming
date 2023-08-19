#include<bits/stdc++.h>
using namespace std;
#define ll long long
int getMinDiv(int n){
	for(int i = 2; i * i <= n; ++i){
		if(n % i == 0){
			return i;
		}
	}
	return n;
}
void solve(){
	int n, m;
	cin >> n >> m;
	if((getMinDiv(n) > m) || (n == 1)){
		cout << "YES\n";
	}else{
		cout << "NO\n";
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