#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vf vector<double>
void solve(){
	// code to solve each test case
	int n ;
	cin >> n;
	string s;
	cin >> s;
	int i = 0; 
	int operations = 0;
	while(i < n){
		if((i + 1 < n) && s[i] == s[i + 1]){
			operations++;
			i += 2;
		}else{
			i++;
			operations++;
		}
	}
	cout << operations << '\n';
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