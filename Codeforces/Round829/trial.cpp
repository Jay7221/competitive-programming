#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
	auto calc = [&](){
		int ans = v.size();
		for(int i = 0; i < v.size() - 1; ++i){
			ans = min(ans, abs(v[i + 1] - v[i]));
		}
		return ans;
	};
	int ans = 0;
	while(next_permutation(v.begin(), v.end())){
		if(ans < calc()){
			ans = calc();
			for(auto c : v)
				cerr << c << ' ';
			cerr << '\n';
		}
	}
	cerr << ans << '\n';
	return 0;
}