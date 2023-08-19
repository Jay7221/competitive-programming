#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		a[i] = s[i] - '0';
	ll sum = accumulate(a.begin(), a.end(), 0);
	if(sum == 0){
		cout << n * m << '\n';
	}else if(sum % 2 == 1 && m % 2 == 1){
		cout << 0 << '\n';
	}else{
		int ans = 0;
		if(m % 2 == 1){
			sum /= 2;
			for(int i = 0; i < n; ++i){
				sum -= a[i];
				if(sum == 0)
					++ans;
			}
		}else{
			for(int i = 0; i < n; ++i){
				if(a[i] == 1)
					break ;
				++ans;
			}
			for(int i = n - 1; i > -1; --i){
				if(a[i] == 1)
					break;
				++ans;
			}
			ans += 1;
		}
		cout << ans << '\n';
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}