#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	stack<int> s;
	for(int i = 0; i < n; i++){
		int j = i - s.size();
		if(a[i] != b[j])
			s.push(a[i]);
		else{
			if(s.size() == 0)
				continue ;
			if(b[j] == s.top()){
				while(s.size() && b[j + 1] == s.top()){
					s.pop();
					j = i - s.size();
				}
			}
		}
	}
	if(s.empty())
		cout << "YES\n";
	else
		cout << "NO\n";
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