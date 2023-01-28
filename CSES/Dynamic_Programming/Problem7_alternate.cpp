#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, x;
	cin >> n>> x;
	vector<int> pages(n), prices(n);
	for(int i= 0;i < n; i++)
		cin >> prices[i];
	for(int i = 0; i < n; i++)
		cin >> pages[i];
	vector<int> dp(x + 1);
	for(int i = 0; i < n ; i++){
		int price = prices[i], page = pages[i];
		for(int j = x ; j > 0; j--){
			if(j - price >= 0){
				dp[j] = max(dp[j], dp[j - price] + page);
			}
		}
	}
	cout << dp[x] ;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	while(t--)
		solve();
}