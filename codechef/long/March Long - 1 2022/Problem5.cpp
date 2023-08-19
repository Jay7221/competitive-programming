#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vf vector<double>
void solve(){
	// code to solve each test case
	string s;
	cin >> s;
	int n = s.size();
	char first = s[0], last = s[n - 1];
	int ans = 0;
	int i = 0;
	int max_substr[n];
	max_substr[0] = 0;
	for(int i = 1; i < n; i++){
		if(s[i] == first || s[i] == last){
			max_substr[i] = 0;
			continue ;
		}
		max_substr[i] = max_substr[i - 1] + 1;
		ans = max(ans, max_substr[i]);
	}
	if(ans > 0){
		cout << ans << '\n';
	}
	else{
		cout << -1 << '\n';
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T; 			// total number of text cases
	cin >> T;
	while(T--){
		solve();
	}
}