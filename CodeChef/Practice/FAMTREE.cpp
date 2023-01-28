#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void max_min(map<int, vector<int> >& tree, vector<ll>& wealth, int ancestor, vector<ll>& max_wel,
 vector<ll>& min_wel){
	max_wel[ancestor] = wealth[ancestor];
	min_wel[ancestor] = wealth[ancestor];
	for(auto c : tree[ancestor]){
		max_min(tree, wealth, c, max_wel, min_wel);
		max_wel[ancestor] = max(max_wel[ancestor], max_wel[c]);
		min_wel[ancestor] = min(min_wel[ancestor], min_wel[c]);
	}
	return ;
}
void solve(){
	int n, root;
	cin >> n;
	vector<ll> wealth(n + 1);
	map<int, vector<int> > tree;
	for(int i = 1; i <= n; i++){
		cin >> wealth[i];
	}
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(x == -1){
			root = i;
			continue ;
		}
		tree[x].push_back(i);
	}
	ll ans = 0;
	vector<ll> max_wel(n + 1, 0), min_wel(n + 1, 0);
	max_min(tree, wealth, root, max_wel, min_wel);
	for(int i = 1; i <= n; i++){
		ans = max(abs(max_wel[i] - wealth[i]), ans);
		ans = max(abs(min_wel[i] - wealth[i]), ans);
	}
	cout << ans << '\n';

}
int main(){
	int t;
	t = 1;
	while(t--){
		solve();
	}
}