#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	int even = 0, odd = 0;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		if(a % 2){
			odd += a;
		}else{
			even += a;
		}
	}
	if(even > odd){
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
