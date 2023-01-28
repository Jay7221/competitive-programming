#include<iostream>
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n], suf[n];
	string s;
	cin >> s;
	for(int i = 0; i < n; ++i){
		if(s[i] == 'Q')
			a[i] = -1;
		else
			a[i] = 1;
		suf[i] = a[i];
	}
	for(int i = n - 2; i > -1; --i){
		suf[i] += suf[i + 1];
	}
	bool flag = true;
	for(int i = 0; i < n; ++i){
		if(suf[i] < 0)
			flag = false;
	}
	if(flag)
		cout << "Yes\n";
	else
		cout << "No\n";

}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}