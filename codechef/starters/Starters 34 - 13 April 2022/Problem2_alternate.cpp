#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	int tot = 0;
	for(int i = 0; i < n; i++)
		tot ^= (s[i] - '0');
	if(k % 2 == 0 && tot){
		cout << "NO\n";
		return ;
	}else{
		cout << "YES\n";
	}
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