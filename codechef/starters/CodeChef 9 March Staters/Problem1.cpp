#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vf vector<double>
void solve(){
	// code to solve each test case
	int n, x;
	cin >> n >> x;
	int a[n];
	int mx = -1;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] < x){
			mx = i;
		}
	}
	cout << mx + 1 << '\n';
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