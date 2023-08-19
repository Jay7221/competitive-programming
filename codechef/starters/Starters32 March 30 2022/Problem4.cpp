#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	map<int, vector<int> > plans;
	for(int i = 0; i < n; i++){
		cin >> b[i];
		plans[b[i]].push_back(i);
	}
	priority_queue<int> to_do;
	int k = 0;
	ll ans = 0;
	double final_ans = 0; 
	while(k < n){
		for(auto c : plans[k]){
			to_do.push(a[c]);
		}
		if(to_do.empty()){
			break ;
		}
		ans += to_do.top();
		to_do.pop();
		k++;
		final_ans = max(final_ans, (double)ans / (double) k);
	}
	while(!to_do.empty()){
		ans += to_do.top();
		to_do.pop();
		k++;
		final_ans = max(final_ans, (double) ans / (double) k);
	}
	cout << fixed << setprecision(6) << final_ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}