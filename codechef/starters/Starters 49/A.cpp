#include<bits/stdc++.h>
using namespace std;
void solve(){
	vector<int> a(3);
	for(int i = 0; i < 3; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	if(count(a.begin(), a.end(), a[0]) >= 2){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}