#include<bits/stdc++.h>
using namespace std;
void solve(int t){
	int n;
	cin >> n;
	int ans = ceil((double)n / 5);
	cout << "Case #" << t << ": " << ans << '\n';
}
int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		solve(t);
	}
}