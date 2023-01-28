#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
bool solve(){
	ll n, m, k;
	cin >> n >> m;
	vector<ll> a(n);
	for(ll i = 0; i < n; ++i)
		cin >> a[i];
	cin >> k;
	vector<ll> b(k);
	for(ll i = 0; i < k; ++i)
		cin >> b[i];
	vector<pair<ll, ll> > aa;
	for(int i = 0; i < n; ++i){
		ll siz = 1, elem = a[i];
		while(elem % m == 0){
			elem /= m;
			siz *= m;
		}
		if(aa.empty()){
			aa.push_back({elem, siz});
		}else if(aa.back().first == elem){
			aa.back().second += siz;
		}else{
			aa.push_back({elem, siz});
		}
	}
	vector<pair<ll, ll> > bb;
	for(int i = 0; i < k; ++i){
		ll siz = 1, elem = b[i];
		while(elem % m == 0){
			elem /= m;
			siz *= m;
		}
		if(bb.empty()){
			bb.push_back({elem, siz});
		}else if(bb.back().first == elem){
			bb.back().second += siz;
		}else{
			bb.push_back({elem, siz});
		}
	}
	return (aa == bb);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		if(solve()){
			cout << "Yes\n";
		}else{
			cout << "No\n";
		}
	}
}