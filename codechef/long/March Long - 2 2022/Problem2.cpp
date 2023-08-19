#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int odd[2] = {0, 0}, even[2] = {0, 0};
	for(int i = 0; i < n; i += 2){
		if(s[i] == '1')
			even[1]++;
		else
			even[0]++;
	}
	for(int i = 1; i < n; i += 2){
		if(s[i] == '1')
			odd[1]++;
		else
			odd[0]++;
	}

	int ans = 0;
	ans += min(even[0], odd[1]);
	if(n % 2){
		ans += min(odd[0], even[1]);
	}
	else{
		if(odd[1] > even[0]){
			ans += min(odd[0], even[1]);
		}
		else{
			ans += max(0, min(odd[0] - 1, even[1]));
		}
	}
	cout << ans << '\n';


}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}