#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	map<int, int> freq;
	for(int i = 0; i < n; i++){
		int L;
		cin >> L;
		freq[L]++;
	}
	int ans = 0;
	bool extra_sticks = 0;		// are there two extra sticks
	for(auto c : freq){
		int k = c.second;
		if(k % 2){
			ans++;
			k++;
		}
		if(k % 4){
			extra_sticks ^= 1;
		}
	}
	if(extra_sticks)
		ans += 2;
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}