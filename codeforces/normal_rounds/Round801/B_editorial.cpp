#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	if(n % 2){
		cout << "Mike\n";
		return ;
	}
	int mn = *min_element(a.begin(), a.end());
	int i = find(a.begin(), a.end(), mn) - a.begin();
	if(i % 2){
		cout << "Mike\n";
	}else{
		cout << "Joe\n";
	}
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