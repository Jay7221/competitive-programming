#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vd vector<double>
void solve(){
	// code to solve each test case
	char c;
	map<char, bool> can_open;
	bool can_reach = 1;
	for(int i = 0; i < 6; i++){
		cin >> c;
		switch(c){
			case 'r':
				can_open['R'] = 1;
				break ;
			case 'g':
				can_open['G'] = 1;
				break ;
			case 'b':
				can_open['B'] = 1;
				break ;
			case 'R':
				if(!can_open['R']){
					can_reach = 0;
				}
				break ;
			case 'G':
				if(!can_open['G']){
					can_reach = 0;
				}
				break ;
			case 'B':
				if(!can_open['B']){
					can_reach = 0;
				}
				break ;
		}
	}
	cerr << '\n';
	if(can_reach){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
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