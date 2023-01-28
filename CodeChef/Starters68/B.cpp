#include<iostream>
#include<vector>
using namespace std;
void solve()
{
	int n;
	string s;
	cin >> n >> s;
	vector<int> freq(26);
	int cur = 1, ans = 0;
	for(int i = 1; i < n; ++i)
	{
		int curChar = s[i] - 'a';
		if(s[i] == s[i - 1]){
			++cur;
		}else{
			cur = 1;
		}
		ans = max(ans, cur - 1);
		ans = max(ans, min(freq[curChar], cur));
		freq[curChar] = max(freq[curChar], cur);
	}
	cout << ans << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}