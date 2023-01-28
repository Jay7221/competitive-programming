#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define debug(a, n) for(int i = 0;i < n ;i++){cerr << a[i] << ' ';} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	int odd = 0, even = 0;
	int k = 10;
	int t = n % k;
	n /= k;
	bool p = t % 2;
	bool ans = 0;
	while(n > 0){
		t = n % k ;
		n /= 10;
		if(t % 2 == p){
			ans = 1;
		}
	}
	if(ans){
		cout << "YES" << '\n';
	}
	else{
		cout << "NO" << '\n';
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}