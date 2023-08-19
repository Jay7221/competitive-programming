#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	int odd = 0, even = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a % 2)
			odd++;
		else
			even++;
	}
	int ans = 0;
	if(odd % 2)
		ans = even;
	else
		ans = min(even, odd / 2);
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}