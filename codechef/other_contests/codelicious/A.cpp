#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int debt = k;
	int ans = -1;
	int income = 5000;
	for(int i = 0; i < n; ++i){
		debt -= (income - a[i]);
		if(debt <= 0){
			ans = i + 1;
			break;
		}
	}
	cout << ans << '\n';
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