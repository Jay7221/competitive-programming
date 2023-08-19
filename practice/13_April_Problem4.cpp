#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
int find(string s, string t, vector<int>& coord){
	int l = -1, i = s.size() - 1, j = t.size() - 1;
	coord.resize(j + 1);
	while(i > -1 && j > -1){
		if(s[i] == t[j]){
			if(l == -1)
				l = i;
			coord[j] = i;
			i--, 	j--;
		}
		else
			i--;
	}
	if(j > -1)
		return -1;
	else
		return l;
}
void solve(){
	string s, t;
	cin >> s >> t;
	vector<int> a;
	int k = find(s, t, a);
	if(k == -1){
		cout << "NO\n";
		return ;
	}
	for(int i = 0; i < t.size(); i++){
		int p = s.find(t[i], a[i] + 1);
		if(p == -1)
			continue ;
		if(!binary_search(a.begin(), a.end(), p)){
			cout << "NO\n";
			return ;
		}

	}

	cout << "YES\n";
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