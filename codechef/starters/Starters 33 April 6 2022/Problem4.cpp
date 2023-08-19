#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, m;
	vector<char> data = {'a', 'b', 'c', 'd', 'e'};
	cin >> n >> m;
	string s, a;
	cin >> s >> a;
	int i = 0, j = 0;
	while(i < n){
		if(j < m && s[i] == a[j]){
			i++;
			j++;
			continue ;
		}
		if(s[i] == '?' && j < m){
			for(auto c : data){
				if(c != a[j])
					s[i]  = c;
			}
		}else if(s[i] == '?'){
			s[i] = 'a';
		}
		i++;
	}
	if(j < m){
		cout << s << '\n';
	}else{
		cout << -1 << '\n';
	}

}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}