#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vf vector<double>
void solve(){
	// code to solve each test case
	int x_1, y_1, x_2, y_2, x_3, y_3;
	cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3;
	int ans = 0;
	if((y_1 == y_2) && (y_1 > y_3)){ans = abs(x_1 - x_2);}
	if((y_1 == y_3) && (y_1 > y_2)){ans = abs(x_1 - x_3);}
	if((y_2 == y_3) && (y_2 > y_1)){ans = abs(x_2 - x_3);}
	cout << ans << '\n';
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