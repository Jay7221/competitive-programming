#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	bool x = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		x ^= (s[i] - '0');
		if(x == 1 && cnt < k - 1 && i != n - 1){
			cnt++;
			x = 0;
		}
	}
	if(cnt == k - 1 && x == 1){
		cout << "YES\n";
		return ;
	}
	x = 0, cnt = 0;
	for(int i = 0; i < n; i++){
		x ^= (s[i] - '0');
		if(x == 0 && cnt < k - 1 && i != n - 1){
			cnt++;
		}
	}
	if(cnt == k - 1 && x == 0){
		cout << "YES\n";
		return ;
	}
	cout << "NO\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}