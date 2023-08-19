#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	s.insert(s.begin(), '0');
	s.insert(s.end(), '1');
	// cerr << s << '\n';
	vector<int> zeroes(n + 2), ones(n + 2);
	for(int i = n; i > 0; i--){
		zeroes[i] = zeroes[i + 1];
		if(s[i] == '0')
			zeroes[i]++;
	}
	for(int i = 1; i < n + 1; i++){
		ones[i] = ones[i - 1];
		if(s[i] == '1')
			ones[i]++;
	}
	int z = 0, o = 0;
	auto calc = [&](){
		for(int i = n; i > 0; i--){
			zeroes[i] = zeroes[i + 1];
			if(s[i] == '0')
				zeroes[i]++;
		}
		for(int i = 1; i < n + 1; i++){
			ones[i] = ones[i - 1];
			if(s[i] == '1')
				ones[i]++;
		}	
	};
	auto cost = [&](int i){
		// the cost of flipping the bit at ith position
		if(s[i] == '1')
			return (zeroes[i] - z) - (ones[i] - o - 1);
		else
			return (ones[i] - o) - (zeroes[i] - z - 1);

	};
	auto flip = [&](int i){
		k--;
		if(s[i] == '1'){
			o++;
			s[i] = '0';
		}else{
			z++;
			s[i] = '1';
		}
	};
	auto ans = [&](){
		calc();
		int ans_ = 0;
		for(int i = 1; i < n + 1; i++){
			if(s[i] == '1')
				ans_ += zeroes[i];
		}
		return ans_ ;
	};
	// z = number of zeroes converted to ones and o = number of ones converted to zeroes 
	int i = 1, j = n;
	while(i < j && k){
		while(i < j && cost(i) <= 0)
			i++;
		while(i < j && cost(j) <= 0)
			j--;
		if(cost(i) > cost(j)){
			flip(i);
			i++;
		}else{
			flip(j);
			j--;
		}
	}
	// cerr << s[1:n] << '\n';
	cout << ans() << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}