#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c <<' ' ;} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int num = 0, ans = 0;
	char prev = 'a';
	for(int i = 0; i < n; i += 2){
		if(s[i] != s[i + 1]){
			ans++;
		}else{
			if(s[i] != prev){
				prev = s[i];
				num++;
			}
		}
	}
	num = max(num, 1);
	cout << ans << ' ' << num << '\n';
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