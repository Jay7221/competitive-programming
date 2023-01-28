#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ';}cerr << '\n';
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	set<int> s;
	for(int i = 1; i < n + 1; ++i)
		s.insert(i);
	vector<int> ans;
	int last = 1;
	int cur = 0, k = 1, done = 0;
	while(done < n){
		if(cur + k < n){
			ans.push_back(cur + k);
			cur += k + k;
			cur %= n;
		}else{
			cur += k;
			cur %= n;
			k += 1;
			ans.push_back(cur);
			cur += k;
			cur %= n;
		}
		++done;
	}
	ans.push_back(*s.begin());
	for(auto c : ans)
		cout << c << ' ' ;
}