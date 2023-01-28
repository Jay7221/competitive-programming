#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7
#define mx (int)(1e5 + 8)
void solve(){
	int n;
	cin >> n;
	vector<int> coins(n);
	for(int i = 0; i < n; i++)
		cin >> coins[i];
	vector<bool> possible(mx, 0);
	possible[0] = 1;
	for(auto c : coins){
		for(int i = mx - 1; i >= 0; i--){
			if(possible[i]){
				if(i + c < mx){
					possible[i + c] = 1;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i < mx; i++){
		if(possible[i])
			ans++;
	}
	cout << ans << '\n';
	for(int i= 1;i < mx;i++){
		if(possible[i])
			cout << i << ' ';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}