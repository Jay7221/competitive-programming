#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	ll sum = 0;
	for(int i = 0; i < n; i++){
		ll a;
		cin >> a;
		sum += a;
	}
	if(sum % (n / 2)){
		cout << "NO\n";
		return ;
	}
	ll k = sum / (n / 2);
	if(k % 2){
		cout << "YES\n";
		return ;
	}else{
		cout << "NO\n";
		return;
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