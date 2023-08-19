#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> freq;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		freq[a[i]]++;
	}
	sort(a.begin(), a.end());
	int max_freq = 0;
	for(auto c : freq){
		max_freq = max(max_freq, c.second);
	}
	int r = max_freq;
	vector<int> d(n);
	for(int i = 0; i < n; i++){
		d[i] = a[(i + r) % n];
	}
	auto check = [&](int i){
		int j = i + 1;
		if(a[i] == d[i])
			return 0;
		if(a[j] == d[j])
			return 0;
		if(a[i] == d[j] && a[j] == d[i])
			return 0;
		return 1;
	};
	for(int i = 0; i < n - 1; i++){
		if(!check(i)){
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
	for(int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << '\n';
	for(int i = 0; i < n; i++)
		cout << d[i] << ' ';
	cout << '\n';
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