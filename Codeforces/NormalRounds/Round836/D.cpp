#include<iostream>
using namespace std;
void solve(){
	int n;
	cin >> n;
	if(n % 2){
		
		return ;
	}else{
		int skip = (n + 2) / 2;
		int k = n - skip;
		for(int i = 1; i <= n + 1; ++i){
			if(i != skip){
				cout << (i + k) << ' ';
			}
		}
		cout << '\n';
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