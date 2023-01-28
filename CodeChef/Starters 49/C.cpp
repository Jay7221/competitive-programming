#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int ones = count(s.begin(), s.end(), '1'), zeroes = count(s.begin(), s.end(), '0');
	int ans = abs(ones / k - zeroes / k);
	if(ones > zeroes){
		if(ones % k > zeroes % k){
			++ans;
		}
	}else{
		if(zeroes % k > ones % k){
			++ans;
		}
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}