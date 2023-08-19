#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	string a;
	cin >> a;
	reverse(a.begin(), a.end());
	string b, c;
	auto add = [&](int flag){
		if(flag == 1){
			b.push_back('1');
			c.push_back('0');
		}else if(flag == 0){
			b.push_back('0');
			c.push_back('0');
		}else{
			b.push_back('0');
			c.push_back('1');
		}
	};
	for(char ch : a){
		if(ch == '0'){
			if(b.size() > 0){
				int cnt = 0;
				while(b.back() == '1'){
					b.pop_back();
					c.pop_back();
					++cnt;
				}
				if(cnt > 1){
					--cnt;
					add(-1);
					while(cnt--){
						add(0);
					}
					add(1);
				}else{
					while(cnt--){
						add(1);
					}
					add(0);
				}
			}else{
				add(0);
			}
		}else{
			b.push_back('1');
			c.push_back('0');
		}
	}
	reverse(b.begin(), b.end());
	reverse(c.begin(), c.end());
	cout << b << '\n' << c << '\n';
	
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
	
	return 0;
}