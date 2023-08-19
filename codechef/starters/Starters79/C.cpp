#include<bits/stdc++.h>
using namespace std;
void solve(){
	int x, y;
	cin >> x >> y;
	int k = min(x, y);
	x -= k;
	y -= k;
	bool flag;
	if(k % 2 == 0){
		// k is even
		// Chef's turn
		if(x >= 2){
			flag = true;
			// Chef wins;
		}else{
			flag = false;
			// Chefina wins
		}
	}
	else{
		// k is odd
		// Chefina's turn
		if(y >= 2){
			flag = false;
			// Chefina wins
		}else{
			flag = true;
			// Chef wins
		}
	}
	if(flag){
		cout << "CHEF\n";
	}else{
		cout << "CHEFINA\n";
	}
		
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	t = 1;
	while(t--){
		solve();
	}

	return 0;
}
