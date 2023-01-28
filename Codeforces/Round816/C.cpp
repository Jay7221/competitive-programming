#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c : a){cerr << c << ' ' ; } cerr << '\n';
ll n, m;
vector<ll> a, back;
set<ll> s;
ll cur_ans = 0;
bool check(ll a, ll b){
	if((a < 1) || (b > n))
		return 0;
	return 1;
}
ll cost(ll l, ll r){
	if(!check(l, r)){
		return 0ll;
	}
	if(l > r){
		return 0ll;
	}
	ll s = r - l + 1;
	ll ans = (l - 1) * (n - r) + (l - 1) * s + s * (n - r) + ((s * (s + 1)) / 2);
	return ans;
}
void merge(int a, int b){
	if(!check(a, b)){
		return ;
	}
	ll r1 = *s.lower_bound(a), r2 = *s.lower_bound(b);
	if(r1 == r2)
		return ;
	ll l1 = back[r1], l2 = back[r2];
	cur_ans -= cost(l1, r1) + cost(l2, r2);
	cur_ans += cost(l1, r2);
	back[r2] = l1;
	s.erase(r1);
}
void split(int a, int b){
	if(!check(a, b)){
		return ;
	}
	ll r1 = *s.lower_bound(a), r2 = *s.lower_bound(b);
	if(r1 != r2)
		return ;
	ll l1 = back[r1], l2 = back[r2];
	cur_ans -= cost(l1, r1);
	l2 = b;
	r1 = a;
	cur_ans += cost(l1, r1) + cost(l2, r2);
	back[r1] = l1, back[r2] = l2;
	s.insert(r1);
	s.insert(r2);
}
void query(){
	ll i, x;
	cin >> i >> x;
	a[i] = x;
	if(a[i] == a[i - 1]){
		merge(i - 1, i);
	}else{
		split(i - 1, i);
	}
	if(a[i] == a[i + 1]){
		merge(i, i + 1);
	}else{
		split(i, i + 1);
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	a.resize(n + 2, -1);
	back.resize(n + 2, n + 2);
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	s.insert(0);
	s.insert(n + 1);
	for(int i = 1; i <= n; ++i){
		ll l = i, r = i;
		back[r] = l;
		while((i + 1) <= n && a[i + 1] == a[l]){
			++i;
			r = i;
			back[r] = l;
		}
		s.insert(r);
	}
	for(auto r : s){
		cur_ans += cost(back[r], r);
	}
	while(m--){
		query();
		cout << cur_ans << '\n';
	}

}