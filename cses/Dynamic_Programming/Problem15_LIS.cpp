#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<int> x(n);
	for(int i = 0; i < n; i++)
		cin >> x[i];
	vector<int> lis;
	for(int i = 0; i < n; i++){
		auto k = lower_bound(lis.begin(), lis.end(), x[i]);
		if(k == lis.end()){
			lis.push_back(x[i]);
		}
		else{
			*k = x[i];
		}
	}
	cout << lis.size() << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}