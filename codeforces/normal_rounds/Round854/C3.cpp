#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	string s, t;
	cin >> s;
	int n = s.size();
	t = s;
	sort(s.begin(), s.end());
	int l = 0, r = n - 1;
	bool isPrev = false;
	char prevChar;
	int i;
	for(i = 0; i < n; ++i){
		if(i == n - 1){
			if(isPrev){
				t[l] = s[i];
				t[r] = prevChar;
				++i;
				++l;
				--r;
				break;
			}else{
				t[r] = s[i];
			}
		}else{
			if(s[i] == s[i + 1]){
				t[l] = s[i];
				t[r] = s[i + 1];
				++i;
			}else{
				if(isPrev){
					t[l] = s[i];
					t[r] = prevChar;
					++i;
					++l;
					--r;
					break;
				}else{
					isPrev = true;
					prevChar = s[i];
				}
			}
		}
		++l;
		--r;
	}
	cerr << s << '\n';
	cerr << t << '\n';
	while(l <= r){
		if(i >= n){
			t[l] = prevChar;
		}else{
			t[l] = s[i];
			++i;
		}
		++l;
	}
	cout << t << "\n";
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
