#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n;
	cin >> n;
	if(n % 2)
		cout << -(n + 1) / 2 << '\n';
	else
		cout << n / 2 << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}