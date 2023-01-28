#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(){
	int A, B, P, Q;
	cin >> A >> B >> P >> Q;
	if(P % A || Q % B){
		cout << "NO" << "\n";
		return ;
	}
	int a =  P / A,  b = Q / B;
	if(abs(a - b) < 2){
		cout << "YES" << "\n";
	}
	else{
		cout << "NO" << "\n";
	}
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