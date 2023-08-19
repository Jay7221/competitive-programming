#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	string s;
	cin >> n;
	cin >> s;
	int z = 0, o = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1')
			o++;
		else
			z++;
	}
	int ans = 0;
	if(z == o)
		ans = z + o;
	else
		ans = 2 * min(z, o) + 1;
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}