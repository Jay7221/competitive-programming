#include<bits/stdc++.h>
using namespace std;
void solve(){
	long long n, m;
	cin >> n >> m;
	if((n + m) % 2){
		cout << "Burenka" << '\n';
	}else{
		cout << "Tonya" << '\n';
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}