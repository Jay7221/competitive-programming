#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>
#define debug(a) for(int i = 0; i < a.size(); i++){cerr << a[i] << ' ' ;} cerr << '\n';
void solve(){
	int n; 
	cin >> n;
	map<int, int> num_wand;
	int a;
	for(int i = 0; i < n; i++){
		cin >> a;
		num_wand[a]++;
	}
	int ans = 0;
	for(auto c : num_wand){
		if(c.first <= c.second){
			ans += (ll)c.first;
		}
	}
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}