#include<bits/stdc++.h>
using namespace std;
void fun(string str,int n,int k,vector<int> &ans)
    {
        if(str.size()==n)
        {
            ans.push_back(stoi(str));
            return ;
        }
        char lastChar=str.back();
        int smallerDigit=int(lastChar)-48-k;
        if(smallerDigit>=0)
        {
            str+=to_string(smallerDigit);
            fun(str,n,k,ans);
            str.pop_back();
        }
        int greaterDigit=int(lastChar)-48+k;
        if(greaterDigit>=0&&greaterDigit<=9&&greaterDigit!=smallerDigit)
        {
            str+=to_string(greaterDigit);
            fun(str,n,k,ans);
            str.pop_back();
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
    vector<int> ans;
        for(int i=1;i<=9;i++)
        {
            fun(to_string(i),n,k,ans);
        }
        return ans;
    }
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> ans = numsSameConsecDiff(n, k);
	sort(ans.begin(), ans.end());
	for(auto elem : ans)
		cout << elem << ' ';
	cout << '\n';
}
int main(int argc, char **argv){
	if(argc > 1){
		freopen(argv[1], "r", stdin);
		freopen("solution.txt", "w", stdout);
	}
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
};
