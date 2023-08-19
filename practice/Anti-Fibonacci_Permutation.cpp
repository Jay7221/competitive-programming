#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vd vector<double>
void solve(){
	// code to solve each test case
	int n;
	cin >> n;
	if(n == 3){
		cout << "3 2 1\n";
		cout << "1 3 2\n";
		cout << "3 1 2\n";
		return ;
	}
	// for(int i = 0; i < n; i++){
	// 	cout << n - i << ' ' ;
	// }
	// cout << '\n';
	for(int i = 0; i < n; i++){
		int k = n - i; 
		for(int i = 0; i < n; i++){
			cout << k << ' ' ;
			k--;
			if(k < 1){
				k = n;
			}
		}
		cout << '\n';
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