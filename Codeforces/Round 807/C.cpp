#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto  c : a){cerr << c << ' ';} cerr << '\n';
#define mx (ll)(1e18 + 7)
ll n, c, q;
string s;
set<ll> st;
map<ll, ll> mp;
ll get_index(ll i){
	if(i < n){
		return i;
	}
	ll ans = *(--st.upper_bound(i));
	ans = mp[ans] + i - ans;
	if(ans < n){
		return ans;
	}
	return get_index(ans);
}
void solve(){
	cin >> n >> c >> q;
	cin >> s;

	st.clear();
	mp.clear();
	st.insert(0ll);

	ll sz = n;


	for(int i = 0; i < c; ++i){
		ll l, r;
		cin >> l >> r;
		--l, --r;	
		mp[sz] = l;
		st.insert(sz);
		sz += r - l + 1;
	}
	for(int i = 0; i < q; ++i){
		ll k;
		cin >> k;
		--k;
		cout << s[get_index(k)] << '\n';
	}
	// cerr << "------------------------------------------------------------------------------------------------------------------------\n";
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}