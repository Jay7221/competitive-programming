#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	char d;
	cin >> n >> d;
	string s;
	cin >> s;
	for(int i = 0; i < n; ++i){
		if(s[i] < d){
			string t = s.substr(0, i);
			t.push_back(d);
			t += s.substr(i, n - i);
			s = t;
			break;
		}
	}
	if(s.size() == n){
		s.push_back(d);
	}
	cout << s << '\n';
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
