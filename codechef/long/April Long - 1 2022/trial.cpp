#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int a, b, c;
	cin >> a;
	if(a == -1)
		return ;
	cin >> b >> c;
	cerr << a << ' ' << b << ' ' << c << '\n';
	cout << ((a ^ b) + (b ^ c) + (c ^ a)) << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}