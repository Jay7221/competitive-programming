#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
       string t;
	   for(int i = 0; i < s.size(); ++i){
		   t.push_back('#');
		   t.push_back(s[i]);
	   }
	   t.push_back('#');
	   int ans = 0;
	   int n = t.size();
	   for(int i = 0; i < n; ++i){
		   int k = 0;
		   while((i + k < n) && (i - k >= 0) && (t[i + k] == t[i - k])){
			   ++k;
		   }
		   if(i % 2 == 0){
			   ans += k / 2;
		   }
		   else{
			   ans += (k + 1) / 2;
		   }

	   }
	   return ans;
    }
};
int main(){
	Solution sol;
	string s;
	cin >> s;
	cout << sol.countSubstrings(s) << '\n';
	return 0;
}
