#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool check1(vector<int> &a){
	// checks if all elements are equal
	int n = a.size();
	for(int i = 1; i < n; ++i){
		if(a[0] != a[i]){
			return false;
		}
	}
	return true;
}
bool check2(vector<int> &a){
	// checks if atleast one element is equal to 1
	int n = a.size();
	for(int i = 0; i < n; ++i){
		if(a[i] == 1){
			return true;
		}
	}
	return false;
}
void print(vector<pair<int, int>> &v){
	cout << v.size() << '\n';
	for(auto [u, v] : v){
		cout << u << ' ' << v << '\n';
	}
}
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	if(check1(a)){
		cout << 0 << '\n';
		return;
	}
	if(check2(a)){
		cout << -1 << '\n';
		return;
	}
	vector<pair<int, int>> ans;
	auto operate = [&](int i, int j){
		ans.push_back({i + 1, j + 1});
		a[i] = ((a[i] + a[j] - 1) / a[j]);
	};
	set<pair<int, int>> st;
	for(int i = 0; i < n; ++i){
		st.insert({a[i], i});
	}
	while(true){
		int mx_ind, mn_ind, mx, mn;
		
		tie(mn,mn_ind) = *st.begin();
		tie(mx, mx_ind) = *(--st.end());
		
		st.erase(st.begin());
		st.erase(--st.end());

		if(mx == mn){
			break;
		}
		
		operate(mx_ind, mn_ind);
		
		st.insert({a[mx_ind], mx_ind});
		st.insert({a[mn_ind], mn_ind});
	}
	print(ans);
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

	return 0;
}
