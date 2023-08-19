#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int a, b;
	cin >> a >> b;
	string s;
	while(a + b){
		if(b == 0){
			s.push_back('0');
			--a;
		}else if(a == 0){
			s.push_back('1');
			--b;
		}else if(s.back() == '0'){
			--b;
			s.push_back('1');
		}else{
			--a;
			s.push_back('0');
		}
	}
	cout << s << '\n';
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