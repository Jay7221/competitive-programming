#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	string s;
	cin >> n;
	cin >> s;
	int l = 0, r = n - 1;
	while((l < r) && (s[l] == s[r])){
		++l;
		--r;
	}
	while((l < r) && (s[l] != s[r])){
		++l;
		--r;
	}
	while((l < r) && (s[l] == s[r])){
		++l;
		--r;
	}
	if(l < r){
		cout << "NO\n";
	}else{
		cout << "YES\n";
	}
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