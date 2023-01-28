#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define vf vector<double>
#define mod (int)(1e9 + 7)
void solve(){
	// code to solve each test case
	int n, q;
	cin >> n >> q;
	string a,b;
	cin >> a >> b;
	int diff[n];
	for(int i = 0; i < n ;i++){
		diff[i] = (int)b[i] - (int)a[i];
		if(diff[i] > 26){
			diff[i] %= 26;
		}
		if(diff[i] < 0){
			diff[i] %= 26;
			diff[i] += 26;
		}
	}
	int sum = 0;
	int alt_sum[n];
	int k = 1;
	for(int i = 0; i < n ;i++){
		sum += k * diff[i];
		sum %= 26;
		k *= -1;
		alt_sum[i] = sum ; 
	}
	// for(int i= 0; i < n ;i++){
	// 	cerr << alt_sum[i] << ' ';
	// }
	for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		l = l - 1;
		r = r - 1;
		if((l == 0) && (alt_sum[r] == 0)){
			cout << "YES\n";
		}
		else if((l == 0) && (alt_sum[r] != 0)){
			cout << "NO\n";
		}
		else if(((alt_sum[r] - alt_sum[l - 1]) % 26 )== 0){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}

	}
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