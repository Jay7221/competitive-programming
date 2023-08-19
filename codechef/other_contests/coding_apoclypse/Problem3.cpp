#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void solve(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int n = 0, s = 0;		//	coins of nitin and sobhagya
	n += a;
	s += b;
	if(s > n){
		n += c;
	}
	else{
		s += c;
	}
	if(s > n){
		n += d;
	}
	else{
		s += d;
	}
	if(s > n){
		cout << 'S' << '\n';
	}
	else{
		cout << 'N' << '\n';
	}
}
int main(){
	fast_io
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}