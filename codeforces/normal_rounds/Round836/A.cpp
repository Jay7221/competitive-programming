#include<iostream>
#include<algorithm>
using namespace std;
void solve(){
	string s;
	cin >> s;
	cout << s;
	reverse(s.begin(), s.end());
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