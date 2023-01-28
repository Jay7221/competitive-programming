#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vf vector<double>
void solve(){
	int n;
	cin >> n;
	int a[n];
	map<int, int> freq_powerups;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		freq_powerups[a[i]]++;
	}
	int s = freq_powerups.size();
	for(int k = 1; k <= n; k++){
		cout << max(k, s) << ' ';
	}
	cout << '\n';
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