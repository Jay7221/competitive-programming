#include <bits/stdc++.h>
using namespace std;
void solve(){
	int N;
	cin >> N;
	for(int i = 2; i <= N; i++){
		cout << i << " ";
	}
	cout << '1';
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