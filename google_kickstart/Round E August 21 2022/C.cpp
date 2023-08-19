#include<bits/stdc++.h>
using namespace std;
void solve(int t){
	// ------------------ INPUT -----------------------------------
	string P, Q;
	int n;
	cin >> n;
	cin >> P;
	// ------------------ End of INPUT ----------------------------

	auto is_pal = [&](string& s){
		int sz = s.size();
		for(int i = 0; i < sz / 2; ++i){
			if(s[i] != s[sz - 1 - i]){
				return 0;
			}
		}
		return 1;
	};
	auto check = [&](int sz){
		string q = P.substr(0, sz);
		bool ans = 1;
		ans = is_pal(q);
		for(int i = 0; i < n; i += sz){
			if(q != P.substr(i, sz)){
				ans = 0;
				break ;
			}
		}
		return ans;
	};

	int cur = n;
	for(int i = 1; i <= n; ++i){
		if(n % i)
			continue ;
		if(check(i)){
			cur = i;
			break ;
		}
	}
	Q = P.substr(0, cur);
	// ------------------ OUTPUT ----------------------------------
	cout << "Case #" << t << ": " << Q << "\n";
	// ------------------ End of OUTPUT ---------------------------
}
int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		solve(t);
	}
}