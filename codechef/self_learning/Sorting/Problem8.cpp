#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vp vector<pair<int, int>>
void solve(){
	int n, x;
	cin >> n >> x;
	map<ll, int> flav;
	ll a;
	for(int i = 0; i < n; i++){
		cin >> a;
		flav[a]++;
	}
	if(x == n){
		cout << 0 << '\n';
		return ;
	}
	for(auto c : flav){
		if(x <= 0){
			break ;
		}
		x -= c.second - 1;
	}
	if(x <= 0){
		cout << flav.size() << '\n'; 
	}
	else{
		cout << flav.size() - x << '\n';
	}


}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	while(T--){
		solve();
	}
	return 0;
}
