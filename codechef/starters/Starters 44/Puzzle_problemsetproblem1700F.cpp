#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug_mat(a) for(auto c : a){for(auto k : c){cerr << k << ' ' ;} cerr << '\n';} cerr << "-----------------------------------------------------------\n\n";
void solve(){
	int n;
	cin >> n;
	cerr << n << '\n';
	vector<vector<int> > initial(2, vector<int>(n)), final(2, vector<int>(n));
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < n; ++j)
			cin >> initial[i][j];
	}
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < n; ++j)
			cin >> final[i][j];
	}
	debug_mat(initial)
	debug_mat(final)
	int tmp = accumulate(initial[0].begin(), initial[0].end(), 0);
	tmp += accumulate(initial[1].begin(), initial[1].end(), 0);
	tmp -= accumulate(final[0].begin(), final[0].end(), 0);
	tmp -= accumulate(final[1].begin(), final[1].end(), 0);
	cerr << tmp << '\n';
	if(tmp != 0){
		cout << -1 << '\n';
	}
	int ans = 0;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}