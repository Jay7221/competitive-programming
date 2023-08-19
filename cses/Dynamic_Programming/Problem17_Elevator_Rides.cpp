#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void print(int s){
	for(int i = 3; i > -1; i--){
		if(s & (1 << i))
			cerr << 1 ;
		else 
			cerr << 0;
	}
}
void solve(){
	int n, x;
	cin >> n;
	cin >> x;
	vector<int> weight(n);
	for(int i = 0; i < n; i++)
		cin >> weight[i];
	pair<int, int> dp[1 << n];
	// dp(s) = {minimum number of rides required to take subset s, weigth of the last ride}
	for(int s = 1; s < (1 << n); s++){
		// print(s);
		// cerr << '\n';
		dp[s] = {n + 1, 0};
		// initially n + 1 rides are needed and last ride is empty
		for(int p = 0; p < n; p++){
			if(s & (1 << p)){
				// if p is in subset s
				auto option = dp[s ^ (1 << p)];
				// print(s ^ (1 << p));
				// cerr  << ' ' << option.first << ' ' << option.second << '\n';
				// firstly remove p from s
				if(option.second + weight[p] <= x){
					// Now if p can be put in the last ride, just put him there 
					// and increase the weight of the last ride
					option.second += weight[p];
				}
				else{
					// else reserve a new ride for p
					// and increase the number of rides
					option.first++;
					option.second = weight[p];
				}
				// cerr << option.first << ' ' << option.second << '\n';
				// set dp of s to the minimum of s and option
				dp[s] = min(dp[s], option);
			}
		}
	}
	// for(int i = 0; i < (1 << n); i++){
	// 	cerr << dp[i].first << ' ' ;
	// }
	cout << dp[(1 << n) - 1].first + 1 << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}