#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	int mx = 0, mn = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] > a[mx])
			mx = i;
		if(a[i] < a[mn])
			mn = i;
	}
	mx++;	mn++;
	cout << mn << ' ' << mx << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}