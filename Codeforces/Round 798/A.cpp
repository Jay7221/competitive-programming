#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<char> a(n), b(m);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int j = 0; j < m; ++j)
		cin >> b[j];
	string c;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int op = 0;
	int i = 0, j = 0;
	bool cur = 0;
	while(i < n && j < m){
		if(op >= k){
			op = 1;
			if(cur == 1){
				c.push_back(a[i++]);
				cur = 0;
			}else{
				c.push_back(b[j++]);
				cur = 1;
			}
		}else{
			++op;
			if(a[i] < b[j]){
				c.push_back(a[i++]);
				if(cur == 1){
					cur = 0;
					op = 1;
				}
			}else{
				c.push_back(b[j++]);
				if(cur == 0){
					cur = 1;
					op = 1;
				}
			}
		}
	}
	cout << c << '\n';
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