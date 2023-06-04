#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	bool flag = 1;
	for(int i = 0; i < n; ++i){
		if(a[i] == 1){
			cout << "CHEF\n";
			return ;
		}
	}
	long long sum = accumulate(a.begin(), a.end(), 0ll);
	if(sum % 2 == 0){
		cout << "CHEFINA\n";
	}else{
		cout << "CHEF\n";
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