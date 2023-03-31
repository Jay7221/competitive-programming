#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int k ;
	cin >> k;
	while(k > 0){
		string s = "00000000";
		for(int i = 0; i < 4; i++){
			if(k){
				s[i] = '1';
				k--;
			}
			if(k){
				s[i + 4] = '1';
				k--;
			}
		}
		cout << s;
		cout.flush();
		cin >> k;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i < t + 1; i++){
		cout << "Case #" << i << ": ";
		cout.flush();
		solve();
	}
}