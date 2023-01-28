#include <bits/stdc++.h>
using namespace std;
void solve(){
	int N;
	cin >> N;
	if(N % 3 == 0){
		if(N % 9 == 0){
			for(int i = 0; i < N - 4; i++){
				cout << '1';
			}
			cout << "0001";

		}
		else{
			for(int i = 0; i < N; i++){
				cout << '1' ;
			}
		}
	}
	else{
		for(int i = 0; i < N; i++){
			cout << '3';
		}
	}
	cout << "\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}