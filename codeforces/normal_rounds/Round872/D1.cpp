#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
vector<vector<int>> tree;
vector<int> subtree;

const int MAX = 2e5 + 7;
vector<int> fact(MAX);
const ll MOD = 1e9 + 7;

int add(ll a, ll b){
	return ((a + b) % MOD);
}
int sub(ll a, ll b){
	return ((a - b) % MOD + MOD) % MOD;
}
int mult(ll a, ll b){
	return ((a * b) % MOD);
}
int power(ll a, ll p){
	int ans = 1, rem = a;
	while(p){
		if(p & 1){
			ans = mult(ans, rem);
		}
		rem = mult(rem, rem);
		p >>= 1;
	}
	return ans;
}
int inv(int a){
	return power(a, MOD - 2);
}
int divide(int a, int b){
	return mult(a, inv(b));
}
int com(int n, int k){
	if(n < k){
		return 0;
	}
	return divide(fact[n], mult(fact[k], fact[n - k]));
}
void pre(){
	fact[0] = 1;
	for(int i = 1; i < MAX; ++i){
		fact[i] = mult(i, fact[i - 1]);
	}
}

ll ans;
void dfs(int u, int p){
	vector<int> vec;
	for(int v : tree[u]){
		if(v != p){
			dfs(v, u);
			subtree[u] += subtree[v];
			vec.push_back(subtree[v]);
		}
	}
	vec.push_back(n - subtree[u]);
	int cur = 1;
	for(int elem : vec){
		cur = add(cur, elem);
	}
	for(int elem : vec){
		cur = sub(cur, elem);
		ans = add(ans, mult(cur, elem));
	}
}
void solve(){
	cin >> n >> k;
	tree.assign(n, vector<int>());
	subtree.assign(n, 1);
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	if(k % 2){
		ans = 1;
	}else{
		ans = 0;
		dfs(0, -1);
		cerr << ans << '\n';
		ans = divide(ans, com(n, k));
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	pre();
	solve();
	
	return 0;
}