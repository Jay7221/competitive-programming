#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	int n, k;
	cin >> n >> k;
	unordered_map<int, int> freq;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		freq[a]++;
	}
	vector<int> freq_list(freq.size());
	int i = 0;
	for(auto c : freq){
		freq_list[i] = c.second;
		i++;
	}
	sort(freq_list.begin(), freq_list.end());
	int mx = freq_list.back();
	n = freq_list.size();
	vector<int> diff_arr = freq_list;
	for(int i = n - 1; i > 0; i--){
		diff_arr[i] -= diff_arr[i - 1];
	}
	ll ans = 0;
	for(int i = n - 1; i >= 0; i--){
		int no_col = n - i;
		if(k / no_col>= diff_arr[i]){
			ans += diff_arr[i] * no_col;
			k -= diff_arr[i] * no_col;
			diff_arr[i] = 0;
		}
		else{
			ans += k;
			diff_arr[i] -= k / no_col;
			k %= no_col;
			diff_arr[i] -= 1;
			diff_arr[i + k] += 1;
		}
	}
	cerr << ans << ' ' << diff_arr[0] << '\n';
	ans += (diff_arr[0] * (diff_arr[0] + 1)) / 2;
	cerr << ans << '\n';
	for(int i = 1; i < n; i++){
		diff_arr[i] += diff_arr[i - 1];
		ans += (diff_arr[i] * (diff_arr[i] + 1) )/ 2;
	}
	cout << ans << '\n';

	
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