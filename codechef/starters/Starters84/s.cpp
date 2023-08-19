#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	int k;
	cin >> k;
	string s;
	cin >> s;
	if(s[0] == '0'){
		s[0] = '1';
		--k;
	}
	while(k--){
		s.push_back('0');
	}
	cout << s << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		solve();
	}
}
