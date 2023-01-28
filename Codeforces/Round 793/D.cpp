#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = count(s.begin(), s.end(), '1');
	if(cnt == 0 || cnt % 2){
		cout << "NO\n";
		return ;
	}
	cout << "YES\n";
	vector<pair<int, int> > ans;
	vector<int> ufull;
	for(int i = 0; i < n; ++i){
		int nex = (i + 1) % n;
		if(s[nex] == '1'){
			ufull.push_back(i);
		}else{
			ans.push_back({i, nex});
		}
	}
	for(int i = 1; i < ufull.size(); ++i){
		ans.push_back({ufull[0], ufull[i]});
	}
	for(auto c : ans)
		cout << c.first + 1 << ' ' << c.second + 1<< '\n';
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