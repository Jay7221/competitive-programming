#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	string s;
	cin >> n;
	cin >> s;
	bool atLeastSeven = 0, upperCase = 0, lowerCase = 0, digit = 0, special = 0;
	for(auto c : s){
		if('0' <= c && c <= '9')
			digit = 1;
		else if('a' <= c && c <= 'z')
			lowerCase = 1;
		else if('A' <= c && c <= 'Z')
			upperCase = 1;
		else if(c == '#' || c == '@' || c == '*' || c == '&')
			special = 1;
	}
	if(!digit)
		s.push_back('1');
	if(!lowerCase)
		s.push_back('a');
	if(!upperCase)
		s.push_back('A');
	if(!special)
		s.push_back('#');
	while(s.size() < 7)
		s.push_back('1');
	cout << s << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i < t + 1; ++i){
		cout << "Case #" << i << ": " ;
		solve();
	}
}