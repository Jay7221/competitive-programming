#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	ll sum = accumulate(a.begin(), a.end(), 0ll);
	sum = 2 * sum - n;
	if(sum % 2 == 1){
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
