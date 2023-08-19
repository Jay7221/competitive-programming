#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
#define mod (ll)(998244353)
ll pow(int p){
    ll ans = 1, tmp = 2;
    while(p){
        if(p & 1){
            ans *= tmp;
            ans %= mod;
        }
        tmp *= tmp;
        tmp %= mod;
        p >>= 1;
    }
    return ans;
}
void solve(){
	int n;
	cin >> n;
	vector<set<int> > s(n + 1);
	int q;
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		s[l].insert(r);
	}
	int k = 0;
	for(int i = 1; i < n + 1; ++i){
	    if(s[i].empty()){
	        continue ;
	    }
		int prev = i;
		set<int> tmp = s[i];
		for(auto c : tmp){
			s[i].erase(c);
			s[prev].insert(c);
			prev = c + 1;
		}
		k += s[i].size();
	}
	ll ans = pow(k);
	cout << ans << '\n';
	return ;
}
int main(){
// 	freopen("inputf.in","r",stdin);
// 	freopen("outputf.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}