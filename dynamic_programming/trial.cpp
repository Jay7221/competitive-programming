#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
bool solve(){
	string s;
	cin >> s;
	int n = s.size();
	auto is_vowel = [&](char ch){
		if((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u'))
			return 1;
		return 0;
	};
	vector<int> vowels;
	for(int i = 0; i < n; ++i){
		if(is_vowel(s[i]))
			vowels.push_back(i);
	}
	for(int i = 0; i < vowels.size() - 2; ++i){
		int x = vowels[i], y = vowels[i + 1];
		for(int j = vowels.size() - 1; j > i + 3; --j){
			int l = vowels[j - 1], r = vowels[j];
			if((s[x] != s[r]) || (s[y] != s[l]))
				continue ;
			bool flag = 1;
			if(r - l != y - x)
				continue ;
			for(int k = 0; k < y - x + 1; ++k){
				if(s[x + k] != s[l + k]){
					flag = 0;
					break ;
				}
			}
			if(flag)
				return 1;
		}
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int tt = 1; tt < t + 1; ++tt){
		cout << "Case #" << tt << ": ";
		if(solve()){
			cout << "Spell!";
		}else{
			cout << "Nothing.";
		}
		cout << '\n';
	}
}