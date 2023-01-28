#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	// string s;
	// cin >> s;
	// int n = s.size();
	// int i = n - 1;
	// if(s[i] < '9'){
	// 	s[i] += 1;
	// 	cout << s << '\n';
	// 	return ;
	// }
	ll n;
	cin >> n;
	ll m = n;
	int k = 9;
	int count = 0;
	while(k == 9){
		k = m % 10;
		m /= 10;
		if(k != 9)
			break;
		count++;
	}
	if(count % 2 == 0)
		cout << n + 1 << '\n';
	else
		cout << n + 2 << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}