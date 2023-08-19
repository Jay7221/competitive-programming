#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vf vector<double>
ll compute(int a[], int n){
	ll sum = 0;
	ll k = 1;
	for(int i = 0; i < n; i++){
		sum += k *(ll) a[i];
		k *= -1;
	}
	return sum ;
}
void solve(){
	// code to solve each test case
	int n ;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i] = abs(a[i]);
	}
	int mn = a[0], mx = a[1];
	for(int i = 0; i < n; i += 2){
		mn = min(mn, a[i]);
	} 
	for(int i = 1; i < n; i += 2){
		mx = max(mx, a[i]);
	}
	ll add_on = 0;
	if(mx > mn){
		add_on = 2 * (mx - mn);
	}
	cout << compute(a, n) + add_on << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T; 			// total number of text cases
	cin >> T;
	while(T--){
		solve();
	}
}