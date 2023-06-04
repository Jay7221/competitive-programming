#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll k;
	cin >> k;
	string ans;
	while(k > 0){
		int d = (k %9);
		k /= 9;
		if(d >= 4){
			++d;
		}
		ans.push_back(d + '0');
	}
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
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
