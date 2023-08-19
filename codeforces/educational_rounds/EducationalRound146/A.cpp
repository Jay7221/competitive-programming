#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool solve(){
	ll n, k;
	cin >> n >> k;
	if(n % 2 == 0){
		return true;
	}
	if((n - k) % 2 == 0){
		return true;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		if(solve()){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}

	return 0;
}
