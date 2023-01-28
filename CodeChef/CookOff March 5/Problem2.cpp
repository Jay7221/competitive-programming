#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx  (unsigned long int)1e5 + 5
#define mod (int)1e9 + 7
void solve(){
	int X, A, B, C;
	cin >> X >> A >> B >> C;
	int costs[] = {A, B, C};
	sort(costs, costs + 3);
	int a = costs[0], b = costs[1];
	cout << a * (X - 1) + b << "\n";
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
