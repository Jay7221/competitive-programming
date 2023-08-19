#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool op1 = 1;
	// op1 = 1 => opration of type 1 can be performed
	// op1 = 0 => operation of type 1 cannot be performed
	for(int i = n - 1; i > -1; ){
		if((i + 1) % 2 == 0){
			int k = (i + 1) / 2;
			for(int j = 0; j < k ; ++j){
				if(s[j] != s[j + k]){
					cout << "NO\n";
					return ;
				}
				op1 = 1;
			}
			i = k - 1;
		}else{
			if(!op1){
				cout << "NO\n";
				return ;
			}
			op1 = 0;
			--i;
		}
	}
	cout << "YES\n";
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}