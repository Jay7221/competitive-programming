#include<bits/stdc++.h>
using namespace std;
string minWindow(string s, string t) {
        string ans = "";
        int n = s.size();
        int l = t.size(), r = n;
        vector<int> reqFreq(60);
        vector<vector<int> > freq(n + 1, vector<int>(60));
        for(int i = 1; i <= n; ++i)
        	freq[i][s[i - 1] - 'A'] = 1;
        for(auto ch : t)
        	++reqFreq[ch - 'A'];
        for(int i = 1; i <= n; ++i){
        	for(char ch = 'a'; ch <= 'z'; ++ch)
        		freq[i][ch - 'A'] += freq[i - 1][ch - 'A'];
        	for(char ch = 'A'; ch <= 'Z'; ++ch)
        		freq[i][ch - 'A'] += freq[i - 1][ch - 'A'];
        }
        auto check = [&](int i, int j){
        	bool ans = true;
        	for(char ch = 'a'; (ch <= 'z') && ans; ++ch){
        		if(freq[j][ch - 'A'] - freq[i - 1][ch - 'A'] < reqFreq[ch - 'A']){
        			ans = false;
        		}
        	}
        	for(char ch = 'A'; (ch <= 'Z') && ans; ++ch){
        		if(freq[j][ch - 'A'] - freq[i - 1][ch - 'A'] < reqFreq[ch - 'A']){
        			ans = false;
        		}	
        	}
        	return ans;
        };
        auto ok = [&](int k){
        	bool ans = false;
        	for(int i = 1, j = k; (j <= n) && (!ans); ++i, ++j){
        		if(check(i, j)){
        			ans = true;
        		}
        	}
        	return ans;
        };
        auto get = [&](int k){
        	pair<int, int> ans = {0, 0};
        	int i = 1, j = k;
        	for(; j <= n; ++i, ++j){
        		if(check(i, j)){
        			ans = {i, j};
        			break ;
        		}
        	}
        	return ans;
        };
        while(l < r){
        	int m = (l + r) / 2;
        	if(ok(m)){
        		r = m;
        	}else{
        		l = m + 1;
        	}
        }
        if(ok(l)){
        	int i, j;
        	tie(i, j) = get(l);
        	--i, --j;
        	ans = s.substr(i, j - i + 1);
        }
        return ans;
    }
int main(){
	string s = "abc", t = "b";
	cin >> s >> t;
	cerr << minWindow(s, t) << '\n';
}