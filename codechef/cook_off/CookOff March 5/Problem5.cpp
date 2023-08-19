#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int N;
	cin >> N;
	if(N < 2){
		cout << "1\n";
		return ;
	}
	int p = 3;
	bool k = 0; // even index
	cout << "1 2 " ;
	for(int i = 2; i < N; i++){
		if(k){
			cout << 2 * p << " ";
			p += 2;
			k = 0;
		}
		else{
			cout << p << " ";
			k = 1;
		}
	}
	cout << '\n';
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	int N;
	while(T--){
		solve();
	}
	return 0;
}
