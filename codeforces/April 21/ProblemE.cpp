#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll n;
	cin >> n;
	vector<vector<ll> > freq(11, vector<ll>(11, 0));
	for(ll i = 0; i < n; i++){
		char a, b;
		cin >> a >> b;
		freq[a - 'a'][b - 'a'] += 1;
	}
	ll ans = 0;
	for(int i = 0; i < 11; i++){
		for(int j = 0; j < 11; j++){
			if(freq[i][j] == 0)
				continue ;
			for(int k = 0; k < 11; k++){
				if(k == j)
					continue ;
				ans += freq[i][k] * freq[i][j];
			}
			for(int k = 0; k < 11; k++){
				if(k == i)
					continue ;
				ans += freq[k][j] * freq[i][j];
			}
		}
	}
	ans = ans / 2ll;
	cout << ans << '\n';
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