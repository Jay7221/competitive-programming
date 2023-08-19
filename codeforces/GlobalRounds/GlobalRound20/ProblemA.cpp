#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	bool win = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		win ^= (a - 1) % 2;
	}
	if(win){
		cout << "errorgorn\n";
	}else{
		cout << "maomao90\n";
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