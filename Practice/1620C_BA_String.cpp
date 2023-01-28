#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll x;
	int n, k;
	cin >> n >> k >> x;
	string s;
	cin >> s;
	--x;
	stack<pair<int, int> > ans;
	for(int i = n - 1; i > -1; i--){
		if(s[i] == 'a'){
			ans.push({0, 1});
		}else{
			int j = i;
			while(j - 1 > -1 && s[j - 1] == s[j])
				--j;
			int p = (i - j + 1) * k + 1;
			ans.push({1, x % p});
			x /= p;
			i = j;
		}
	}
	while(ans.size()){
		int t,s;
		tie(t, s) = ans.top(), ans.pop();
		if(t == 0){
			cout << 'a' ;
		}else{
			while(s-- > 0){
				cout << 'b';
			}
		}
	}
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