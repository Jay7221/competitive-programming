#include<iostream>
using namespace std;
void solve(){
	int A, B, C;
	cin >> A >> B >> C;
	int prev = 0;
	for(int i = 0; i < 27; ++i){
		int a = (1 & (A >> i)), b = (1 & (B >> i)), c = (1 & (C >> i));
		if((a + b + prev) % 2 != c){
			a ^= 1;
			b ^= 1;
			c ^= 1;
		}
		prev = (a + b + prev) / 2;
	}
	if(prev == 0){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}