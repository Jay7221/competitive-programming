#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a)
ll dfs(ll a, ll& final_ans, map<ll, vector<ll> >& tree, ll fun[]){
	if(tree[a].size() == 0){
		final_ans += fun[a];
		// cerr << a << " : " << final_ans << '\n';
		return fun[a];
	}
	vector<ll> child_fun;
	for(auto c : tree[a]){
		child_fun.push_back(dfs(c, final_ans, tree, fun));
	}
	debug(child_fun)
	sort(child_fun.begin(), child_fun.end());
	ll ans = fun[a];
	if(child_fun[0] < ans){
		final_ans += ans - child_fun[0];
	}else{
		ans = child_fun[0];
	}
	// cerr << a << " : " << final_ans << '\n';
	return ans;
}
void solve(){
	ll n;
	cin >> n;
	ll fun[n + 1];
	fun[0] = 0;
	for(ll i = 1; i <= n; i++)
		cin >> fun[i];
	map<ll, vector<ll> > tree;		// the points in vector point to the int
	for(ll i = 1; i <= n; i++){
		ll p;
		cin >> p;
		tree[p].push_back(i);
	}
	ll final_ans = 0;
	dfs(0, final_ans, tree, fun);
	cout << final_ans ;
}
int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
		cout << '\n';
	}
}