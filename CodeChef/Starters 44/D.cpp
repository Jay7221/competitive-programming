#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, int> freq;
	for(auto ch : s)
		++freq[ch];
	int mx = 0, count_mx = 0;
	for(char ch = 'a'; ch <= 'z'; ++ch){
		if(freq[ch] > mx){
			mx = freq[ch];
			count_mx = 1;
		}
		else if(freq[ch] == mx){
			++count_mx;
		}
	}
	if(mx > (n + 2) / 3){
		cout << "NO\n";
		return ;
	}
	if(mx == ( ( n + 2 ) / 3 )){
		int tmp = n % 3;
		if(tmp == 0)
			tmp = 3;
		if(count_mx > tmp){
			cout << "NO\n";
			return ;
		}
	}
	vector<pair<int, int> > v;
	for(int i = 0; i < 26; ++i){
		v.push_back( {freq[i + 'a'], i} );
	}
	vector<char> b(n);
	set<int> c1, c2, c3;
	for(int i = 0; i < n; ++i){
		if(i % 3 == 0)
			c1.insert(i);
		else if(i % 3 == 1)
			c2.insert(i);
		else
			c3.insert(i);
	}
	sort(v.rbegin(), v.rend());
	for(auto c : v){
		cerr << c.first << ' ' << (c.second + 'a') << '\n';
	}
	cerr<< "------------------------------------\n\n";
	int limit = (n + 2) / 3;
	for(int i = 0; i < n; ++i){
		char ch = v[i].second + 'a';
		int f = v[i].first;
		if(f == limit){
			if(c1.size() == limit){
				while(c1.size()){
					b[*c1.begin()] = ch;
					c1.erase(c1.begin());
				}
			}else if(c2.size() == limit){
				while(c2.size()){
					b[*c2.begin()] = ch;
					c2.erase(c2.begin());
				}
			}else if(c3.size() == limit){
				while(c3.size()){
					b[*c3.begin()] = ch;
					c3.erase(c3.begin());
				}
			}else{
				cout << "NO\n";
				return ;
			}
		}else{
			while(f--){
				if(c1.size()){
					int k = *c1.begin();
					c1.erase(c1.begin());
					b[k] = ch;
				} else if(c2.size()){
					int k = *c2.begin();
					c2.erase(c2.begin());
					b[k] = ch;
				} else if(c3.size()){
					int k = *c3.begin();
					c3.erase(c3.begin());
					b[k] = ch;
				}else{
					cout << "NO\n";
					return ;
				}
			}
		}
	}
	cout << "YES\n";
	for(auto ch : b)
		cout << ch;
	cout << '\n';
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