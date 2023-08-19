#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> p(n);
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	vector<vector<int> > a(n), b(n);
	for(int i = 0; i < n; i++){
		for(int j = 0;j < n; j++){
			if(p[i] > p[j]){
				b[i].push_back(j)
			}else{
				a[i].push_back(j);
			}
		}
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