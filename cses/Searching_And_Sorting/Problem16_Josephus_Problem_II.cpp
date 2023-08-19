#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
int main(){
	int n, k;
	cin >> n >> k;
	ordered_set s;
	for(int i = 1; i <= n; ++i){
		s.insert(i);
	}
	vector<int> ans;
	int pos = 0;
	while(s.size()){
		pos = (pos + k) % n;
		ans.push_back(*s.find_by_order(pos));
		s.erase(s.find_by_order(pos));
		--n;
	}
	for(auto elem : ans)
		cout << elem << ' ';
	cout << '\n';
}