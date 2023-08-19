#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vf vector<double>
void solve(){
	// code to solve each test case
	string s, t;
	cin >> s >> t;
	string m = s;
	for(int i = 0; i < 5; i++){
		if(s[i] == t[i]){
			m[i] = 'G';
		}
		else{
			m[i] = 'B';
		}
	}
	cout << m << '\n';
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
	cout << "Hello World\n";
}