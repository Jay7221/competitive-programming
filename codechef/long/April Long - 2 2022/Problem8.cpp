#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void debug(stack<int> s1, stack<int> s2){
	while(!s1.empty()){
		cerr << s1.top() << ' ';
		s1.pop();
	}
	cerr << '\n';
	while(!s2.empty()){
		cerr << s2.top() << ' ';
		s2.pop();
	}
	cerr << '\n' << '\n';
}
void solve(){
	int n, k;
	string s;
	cin >> n >> k >> s;
	// cerr << n << ' ' << s << '\n';
	stack<ll> s1, s2;
	ll cur = 0;
	for(int i = n - 1; i > -1; i--){
		if(s[i] == '0')
			cur++;
		else{
			if(cur != 0){
				// cerr << cur << ' ' << i << '\n';
				s1.push(cur);
			}
		}
	}
	cur = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1')
			cur++;
		else{
			if(cur != 0){
				// cerr << cur << ' ' << i <<  '\n';
				s2.push(cur);
			}
		}
	}
	// debug(s1, s2);
	// int o = 0, z = 0;
	// while(k > 0 && !s1.empty() && !s2.empty()){
	// 	k--;
	// 	if(s1.top() - z > s2.top() - o){
	// 		s1.pop();
	// 		o++;
	// 	}
	// 	else{
	// 		s2.pop();
	// 		z++;
	// 	}
	// }
	if(s1.empty()){
		cout << 0 << '\n';
		return ;
	}
	ll ans = 0;
	if(s1.top() > s2.top()){
		while(k-- && !s1.empty())
			s1.pop();
		while(!s1.empty()){
			ans += s1.top();
			s1.pop();
		}
	}else{
		while(k-- && !s2.empty()){
			s2.pop();
		}
		while(!s2.empty()){
			ans += s2.top();
			s2.pop();
		}
	}
	// while(!s1.empty()){
	// 	ans += s1.top() - z;
	// 	s1.pop();
	// }
	cout << ans << '\n';
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