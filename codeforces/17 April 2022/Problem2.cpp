#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string ans = s;
	vector<int> f(n, 0);
	int rem = k;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			if(k % 2 == 1){
				if(rem > 0){
					rem--;
					f[i] += 1;
				}else{
					ans[i] = '0';
				}
			}
		}else{
			if(k % 2 == 1){
				ans[i] = '1';
			}else{
				if(rem > 0){
					ans[i] = '1';
					f[i] += 1;
					rem--;
				}
			}
		}
	}
	if(rem > 0){
		f[n - 1] += rem;
		if(rem % 2 == 1){
			ans[n - 1] = '0' + 1 ^ (ans[n - 1] - '0');
		}
	}
	cout << ans << '\n';
	for(int i = 0; i < n; i++)
		cout << f[i] << ' ' ;
	cout << '\n';
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