#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>
#define debug(a, n) for(int i = 0; i < n; i++){cerr << a[i] << ' ' ;} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	int s[n];
	s[0] = a[0];
	for(int i = 1; i < n; i++){
		s[i] = a[i] + s[i - 1];
	}
	debug(s, n)
	int tot = s[n - 1];
	
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}