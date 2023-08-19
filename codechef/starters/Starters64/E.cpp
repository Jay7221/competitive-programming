#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n - 1);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n - 1; ++i){
		int x = a[i] ^ a[i + 1];
		for(int j = 30; j >= 0; --j){
			if(x & (1 << j)){
				if(a[i] < a[i + 1])
					b[i] = -(j + 1);
				else
					b[i] = (j + 1);
				break ;
			}
		}
	}
	multiset<int> s;
	int ans = 1;
	int r = -1;
	for(int l = 0; l < n - 1; ++l){
		while((r + 2 < n) && (s.find(-b[r + 1]) == s.end())){
			++r;
			s.insert(b[r]);
		}
		ans = max(ans, r - l + 2);
		s.erase(s.find(b[l]));
	}
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}