#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx  (unsigned long int)1e5 + 5
#define mod (int)1e9 + 7
void solve(){
	int X, Y;
	cin >> X >> Y;
	int m = X % 2, n = Y % 2;
	if((m + n) % 2 == 0){
		cout << "Janmansh" << "\n";
	}
	else{
		cout << "Jay" << "\n";
	}
}
int main() {
	// your code goes here
	int T;
	cin >> T;
	int N;
	while(T--){
		solve();
	}
	return 0;
}
