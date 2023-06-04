#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	ll sum = accumulate(a.begin(), a.end(), 0ll);
	ll mn = *min_element(a.begin(), a.end());
	bool flag;
	if(n % 2 == 1){
		if(sum % 2 == 0){
			flag = false;
		}else{
			flag = true;
		}
	}else{
		if((sum % 2) || (mn % 2)){
			flag = true;
		}else{
			flag = false;
		}
	}
	if(flag){
		cout << "CHEF\n";
	}else{
		cout << "CHEFINA\n";
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