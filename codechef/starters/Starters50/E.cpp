#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<vector<int> > ans;
	vector<int> index;
	ll mn = *min_element(a.begin(), a.end()), mx = *max_element(a.begin(), a.end());
	// suppose that mn is the minimum element in a and mx is the maximum element

	// suppose that mx - a[i] <= a[i] - mn for some a[i]
	// now if we change a[i] to a[i] - mx, then abs(a[i] - mx) <= abs(mx - mn) / 2


	// so for every iteration we are halving the value of abs(mx - mn)
	// thus in log2(mx - mn) steps we can make mx = mn = 0


	while(mn < mx){
		int ind_mn, ind_mx;
		for(int i = 0; i < n; ++i){
			if(a[i] == mn)
				ind_mn = i;
		}
		vector<int> s;
		for(int i = 0; i < n; ++i){
			if(abs(a[i] - mn) <= abs(a[i] - mx)){
				a[i] -= mn;
				s.push_back(i);
			}
		}
		if(s.size()){
			ans.push_back(s);
			index.push_back(ind_mn);
		}

		mn = *min_element(a.begin(), a.end()), mx = *max_element(a.begin(), a.end());

		for(int i = 0; i < n; ++i){
			if(a[i] == mx)
				ind_mx = i;
		}
		s.clear();
		for(int i = 0; i < n; ++i){
			if(abs(a[i] - mx) <= abs(a[i] - mn)){
				a[i] -= mx;
				s.push_back(i);
			}
		}
		if(s.size()){
			ans.push_back(s);
			index.push_back(ind_mx);
		}

		mn = *min_element(a.begin(), a.end()), mx = *max_element(a.begin(), a.end());
	}
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); ++i){
		cout << ans[i].size() << '\n';
		for(auto c : ans[i])
			cout << c + 1 << ' ';
		cout << '\n';
		cout << "- " << index[i] + 1 << '\n';
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}