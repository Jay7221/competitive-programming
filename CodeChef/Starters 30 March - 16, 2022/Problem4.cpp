#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define debug(a) for(int i = 0; i < a.size(); i++){cerr << a[i] << ' ';} cerr << '\n';
void lis(vi& a, vi& s){
	int n = a.size();
	vi seq;
	seq.push_back(a[0]);
	s[0] = 1;
	for(int i = 1; i < n; i++){
		int k = lower_bound(seq.begin(), seq.end(), a[i]) - seq.begin();
		if(k < seq.size() && k >= 0){
			seq[k] = a[i];
		}
		if(a[i] > seq[seq.size() - 1]){
			seq.push_back(a[i]);
		}
		if(a[i] < seq[0]){
			seq.insert(seq.begin(), a[i]);
		}
		s[i] = seq.size();
	}
}
// void lis_suf(vi& a, vi& s){
// 	int n = a.size();
// 	vi seq;
// 	seq.push_back(a[n - 1]);
// 	s[n - 1] = 1;
// 	for(int i = n - 2; i >= 0; i--){
// 		int k = lower_bound(seq.begin(), seq.end(), a[i]) - seq.begin();
// 		if(k > 0){
// 			seq[k - 1] = a[i];	
// 		}
// 		if(a[i] < seq[0]){
// 			seq.insert(seq.begin(), a[i]);
// 		}
// 		s[i] = seq.size();
// 	}
// }
void solve(){
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vi p(n);
	vi s(n);
	lis(a, p);
	reverse(a.begin(), a.end());
	for(int i = 0; i < n; i++)
		a[i] *= -1;
	lis(a, s);
	reverse(s.begin(), s.end());
	// debug(p)
	// debug(s)
	// cerr << '\n';
	int ans = 1;
	for(int i = 0; i < n - 1; i++){
		ans = max(ans, p[i] + s[i + 1]);
	}
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}