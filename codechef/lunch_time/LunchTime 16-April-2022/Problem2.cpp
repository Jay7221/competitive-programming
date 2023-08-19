#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define mod (int)(1e9 + 7)
void solve(){
	ll n, m, l;
	cin >> n >> m >> l;
	ll cur = l + n - 1;
	// number of buckets of the current friend
	while(cur >= l){
		m %= cur;
		cur = m;
	}
	cout << m << '\n';
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