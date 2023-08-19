#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<char> alphabet;
	set<char> st;
	map<char, int> freq;
	for(char ch : s){
		st.insert(ch);
		++freq[ch];
	}
	int mx = 0, mn = n;
	for(char ch : st){
		alphabet.push_back(ch);
		mx = max(mx, freq[ch]);
		mn = min(mn, freq[ch]);
	}
	if(mx - mn > k){
		cout << -1 << '\n';
		return ;
	}
	int m = alphabet.size();
	string res;
	for(int i = m - 1; i >= 0; --i){
		int cnt = min(k, freq[alphabet[i]]);
		while(cnt--){
			res.push_back(alphabet[i]);
			--freq[alphabet[i]];
		}
		while(freq[alphabet[i]] > 0){
			for(int j = i - 1; j >= 0; --j){
				if(freq[alphabet[j]] > 0){
					res.push_back(alphabet[j]);
					--freq[alphabet[j]];
				}
			}
			res.push_back(alphabet[i]);
			--freq[alphabet[i]];
		}
	}
	reverse(res.begin(), res.end());
	cout << res << '\n';
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
