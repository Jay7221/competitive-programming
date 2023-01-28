#include<bits/stdc++.h>
using namespace std;
void solve(){
	long long X;
	cin >> X;
	bool flag = false;
	for(long long a = 0; a <= sqrt(X); ++a){
		long long b = (X - 2 * a) / (2 + a);
		if( a > 0 && b > 0 && (2 * a + 2 * b + a * b == X)){
			flag = true;
			break ;
		}
	}
	if(flag){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}
int main(){
	int TESTCASES;
	cin >> TESTCASES;
	for(int testcase = 1; testcase <= TESTCASES; ++testcase){
		solve();
	}
}