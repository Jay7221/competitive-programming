#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c : a){cerr << c;} cerr << '\n';
void solve(){
	int x ;
	cin >> x;
	if(!(x & (x - 1))){
		cout << -1 << '\n';
		return ;
	}
	if(x % 2){
		cout << -1 << '\n';
		return ;
	}
	int a = 0, b = 0, c = 0;
	int k = 2;
	int turn = 0;
	while(k <= x){
		if(k & x){
			if(turn){
				a += k >> 1;
				turn ^= 1;
			}else{
				b += k >> 1;
				turn ^= 1;
			}
		}
		k = k << 1;
	}
	cout << a << ' ' << b << ' '  << c << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}