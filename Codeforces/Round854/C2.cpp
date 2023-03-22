#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	string s;
	cin >> s;
	int n = s.size();
	deque<char> d;
	sort(s.rbegin(), s.rend());
	bool flag = true;
	for(char ch : s){
		if(flag){
			d.push_front(ch);
		}else{
			d.push_back(ch);
		}
		flag ^= 1;
	}
	string t;
	for(char ch : d){
		t.push_back(ch);
	}
	for(int l = 0, r = n - 1; l < r; ++l, --r){
		if(t[l] != t[r]){
			if(t[l] < t[r]){
				swap(t[l], t[r]);
			}
			if(r - l < 2){
				continue;
			}
			sort(t.begin() + l + 1, t.begin() + r);
			if(t[l] == t[r - 1]){
				while(r - l > 1){
					swap(t[r], t[r - 1]);
					++l;
					--r;
				}
			}
			break;
		}
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
