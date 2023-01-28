#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	string s;
	cin >> s;
	int n = s.size();
	vector<bool> a(n, 0);
	stack<int> st;
	for(int i = 0; i < n; i++){
		if(s[i] == '(')
			st.push(i);
		else{
			if(st.size()){
				int j = st.top();
				st.pop();
				a[i] = a[j] = 1;
			}
		}
	}
	int ans = 0, sz = 0;
	for(int i = 0; i < n; i++){
		if(a[i]){
			ans += 1;
			while(i + 1 < n && a[i + 1])
				i++;
		}else{
			sz++;
		}
	}
	cout << sz << ' ' << ans << '\n';
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