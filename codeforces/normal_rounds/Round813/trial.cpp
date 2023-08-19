#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
int main(){
	auto calc = [&](vector<int>& v){
		int ans = 0;
		for(int i = 1; i <= v.size(); ++i){
			ans += lcm(i, v[i - 1]);
		}
		return ans;
	};
	vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int mx = 0;
	while(next_permutation(a.begin(), a.end())){
		mx = max(mx, calc(a));
	}
	cerr << mx << '\n';
	while(next_permutation(a.begin(), a.end())){
		if(calc(a) == mx){
			debug(a)
		}
	}
}