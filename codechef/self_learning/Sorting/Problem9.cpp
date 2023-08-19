#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vp vector<pair<int, int>>
void solve(){
	int n, k;
	cin >> n >> k ;
	set<int> a;
	int x;
	for(int i = 0; i < n; i++){
		cin >> x;
		a.insert(x);
	}
	int ans = k;
	for(auto c : a){
		if(c <= ans){
			ans++;
		}
	}
	cout << ans  << '\n';
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
