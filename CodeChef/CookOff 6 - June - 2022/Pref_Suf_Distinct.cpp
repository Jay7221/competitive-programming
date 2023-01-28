#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> p(n), s(n);
	for(int i = 0; i < n; ++i)
		cin >> p[i];
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	bool flag = 1;
	if((p[0] != 1) || (s[n - 1] != 1) || (p[n - 1] != s[0]))
		flag = 0;
	if(!flag){
		cout << "NO\n";
		return ;
	}
	int cur = 0;
	int cp = 0, cs = 0;
	for(int i = 0; i < n; ++i){
		cp = p[i], cs = s[i];
		if(i > 0)
			cp -= p[i - 1];
		if(i < n - 1)
			cs -= s[i + 1];
		if(cp == 1 && cs == 1){
			continue ;
		}
		else if(cp == 1 && cs == 0){
			++cur;
		}
		else if(cp == 0 && cs == 1){
			if(cur <= 0){
				flag = 0;
				break ;
			}
			--cur;
		}
		else if(cp == 0 && cs == 0){
			if(cur <= 0){
				flag = 0;
				break ;
			}
		}
		else{
			flag = 0;
			break ;
		}
	}
	if(flag){
		cout << "YES\n";
	}else{
		cout << "NO\n";
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