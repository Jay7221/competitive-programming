#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	auto is_pal = [&](int l, int r){
		bool flag = true;
		for(int i = l, j = r; i < j; ++i, --j){
			if(s[i] != s[j])
				flag = false;
		}
		return flag;
	};
	if(count(s.begin(), s.end(),s[0]) == 2 *n){
		cout << -1 << '\n';
		return ;
	}
	if(!is_pal(0, 2 * n - 1)){
		cout << 1 << '\n';
		cout << (2 * n) << '\n';
	}else if(!(is_pal(0, n - 1)) && !(is_pal(n, 2 * n - 1))){
		cout << 2 << '\n';
		cout << n << ' ' << n << '\n';
	}else if(!(is_pal(0, n)) && !(is_pal(n + 1, 2 * n - 1))){
		cout <<  2 << '\n';
		cout << (n + 1) << ' ' << (n - 1) << '\n';
	}else{
		cout << -1 << '\n';
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}