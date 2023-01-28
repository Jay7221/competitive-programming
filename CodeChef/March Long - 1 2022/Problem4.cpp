#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vf vector<double>
void solve(){
	// code to solve each test case
	int n, x;
	cin >> n >> x;
	int a, b, c;
	a = x / 3;
	b = x % 3;
	if(b > 0){
		b -= 3;
		a += 1;
	}
	b *= -1 ;
	c = n - (a + b);
	if((a <= n) && (b <= n) && (c >= 0) && (c <= n)){
		cout << "YES" << '\n';
		cout << a << ' ' << b << ' ' << c << '\n';
	}
	else{
		cout << "NO" << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T; 			// total number of text cases
	cin >> T;
	while(T--){
		solve();
	}
}