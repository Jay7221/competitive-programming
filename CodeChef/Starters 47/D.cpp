#include<bits/stdc++.h>
using namespace std;
const int mx = (1 << 16) + 7;
vector<tuple<int, int, int> > v;
vector<int> highest(mx);
bool is_possible(int n, int x){
	if(n == 1){
		return x == 1;
	}
	if(n == 2){
		if(x == 3){
			v.push_back({1, 1, 2});
			return 1;
		}
		return 0;
	}
	if(n == 3){
		if(x == 0){
			v.push_back({1, 1, 2});
			v.push_back({2, 3, 3});
		}else if(x == 1){
			v.push_back({2, 2, 3});
			v.push_back({1, 1, 1});
		}else if(x == 2){
			v.push_back({2, 1, 3});
			v.push_back({1, 2, 2});
		}else if(x == 3){
			v.push_back({1, 1, 2});
			v.push_back({1, 3, 3});
		}else{
			return 0;
		}
		return 1;
	}
	int a = log2(n), b = log2(x);
	if(a < b){
		return 0;
	}
	if(a == b){
		if(n % 2 == 0){
			int cur = (1 << a);
			for(int i = (1 << a) + 1; i < n + 1; ++i){
				v.push_back({2, cur, i});
				cur = cur ^ i;
			}
			if(is_possible((1 << a) - 1, cur ^ x)){
				v.push_back({2, cur, cur ^ x});
				return 1;
			}else{
				return 0;
			}
		}else{
			int cur = (1 << a) | ((1 << a) + 1);
			v.push_back({1, (1 << a), (1 << a) + 1});
			for(int i = (1 << a) + 2; i < n + 1; ++i){
				v.push_back({2, cur, i});
				cur ^= i;
			}
			if(is_possible((1 << a) - 1, cur ^ x)){
				v.push_back({2, cur, cur ^ x});
				return 1;
			}else{
				return 0;
			}
			
		}
	}
	if(n % 2 == 0){
		if(n == (1 << a)){
			return 0;
		}
		int cur = (1 << a) | ((1 << a) + 1);
		v.push_back({1, (1 << a), (1 << a) + 1});
		for(int i = (1 << a) + 2; i < n + 1; ++i){
			v.push_back({2, cur, i});
			cur ^= i;
		}
		if(is_possible((1 << a) - 1, cur ^ x)){
			v.push_back({2, cur, cur ^ x});
			return 1;
		}else{
			return 0;
		}
	}else{
		int cur = (1 << a);
		for(int i = (1 << a) + 1; i < n + 1; ++i){
			v.push_back({2, cur, i});
			cur = cur ^ i;
		}
		if(is_possible((1 << a) - 1, cur ^ x)){
			v.push_back({2, cur, cur ^ x});
			return 1;
		}else{
			return 0;
		}
	}
	return 0;
}
void solve(){
	int n, x;
	cin >> n >> x;
	v.clear();
	if(is_possible(n, x)){
		for(auto p : v){
			int a, b, c;
			tie(a, b, c) = p;
			cout << a << ' ' << b << ' ' << c << '\n';
		}
	}else{
		cout << -1 << '\n';
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}