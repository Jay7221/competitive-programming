#include<bits/stdc++.h>
using namespace std;
int calculate(map<int, vector<int> >& tree, vector<int>& salary, int max_sal, int cur){
	if(salary[cur] > max_sal){
		max_sal = salary[cur];
	}
	int ans = max_sal - salary[cur];
	for(auto c : tree[cur]){
		ans = max(ans, calculate(tree, salary, max_sal, c));
	}
	return ans ;
}
void solve(){
	int n;
	cin >> n;
	int root;
	vector<int> salary(n + 1);
	map<int, vector<int> > tree;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		salary[i] = x;
	}
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(x == -1){
			root = i;
			continue;
		}
		tree[x].push_back(i);
	}
	cout << calculate(tree, salary, salary[root], root) << '\n';

}
int main(){
	int t;
	t = 1;
	while(t--){
		solve();
	}
}