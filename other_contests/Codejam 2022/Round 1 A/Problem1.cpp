#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	string s;
	cin >> s;
	int n = s.size();
	int i = 0;
	string ans;
	while(i < n){
		if(i + 1 < n && s[i] < s[i + 1])
		{
			ans.push_back(s[i]);
			ans.push_back(s[i]);
			i++;
		}
		else if(i + 1 < n && s[i] > s[i + 1]){
			ans.push_back(s[i]);
			i++;
		}
		else if(i == n - 1){
			ans.push_back(s[i]);
			i++;
		}
		else if(s[i] == s[i + 1]){
			int cnt = 1;
			while(i < n - 1 && s[i] == s[i + 1]){
				cnt++;
				i++;
			}
			if(i < n - 1 && s[i] < s[i + 1]){
				while(cnt--){
					ans.push_back(s[i]);
					ans.push_back(s[i]);
				}
				i++;
			}else{
				while(cnt--){
					ans.push_back(s[i]);
				}
				i++;
			}
		}
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
	cout << "Case #" << i << ": " ;
	solve();
	}
}