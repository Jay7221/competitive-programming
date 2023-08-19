#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n ;
	string s, t;
	cin >> s >> t;
	if(count(s.begin(), s.end(), 'a') != count(t.begin(), t.end(), 'a')){
		cout << "NO\n";
		return ;
	}
	if(count(s.begin(), s.end(), 'c') != count(t.begin(), t.end(), 'c')){
		cout << "NO\n";
		return ;
	}
	if(count(s.begin(), s.end(), 'b') != count(t.begin(), t.end(), 'b')){
		cout << "NO\n";
		return ;
	}
	int cur = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] == 'c' || t[i] == 'c'){
			if(cur != 0){
				cout << "NO\n";
				return ;
			}
		}
		cur += (s[i] == 'a');
		cur -= (t[i] == 'a');
		if(cur < 0){
			cout << "NO\n";
			return ;
		}
	}
	cur = 0;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	for(int i = 0; i < n; ++i){
		if(s[i] == 'a' || t[i] == 'a'){
			if(cur != 0){
				cout << "NO\n";
				return ;
			}
		}
		cur += (s[i] == 'c');
		cur -= (t[i] == 'c');
		if(cur < 0){
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
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
}