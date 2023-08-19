#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ones = 0, zeroes = 0;
	for(char ch : s){
		if(ch == '0'){
			++zeroes;
		}else{
			++ones;
		}
	}
	int cnt = min(ones, zeroes);
	if(cnt % 2){
		cout << "Zlatan\n";
	}else{
		cout << "Ramos\n";
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

	return 0;
}
