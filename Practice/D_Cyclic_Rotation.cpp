#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
// Comments - This question consumed a lot of time during practice, even after reading the 
// editorial. The major reason was my inability to think beyond while I already knew.
// The real turning point was when I started to think of new testcases myself, rather than those
// given in the problem set. It was when I really started to notice the boundry conditions and
// the large variations that may come in the input.
// So any time in future where you get wrong answer verdict despite beign quite sure
// of your logic think of all the different variations that are possible and which one of those
//  may lead to a fall in your logic.
// Also try to follow through your code for your invented testcases
void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	int i = n - 1, j = n - 1;
	multiset<int> s;
	bool pos = 1;
	while(j > -1){
		while(j > 0 && b[j] == b[j - 1]){
			s.insert(b[j]);
			--j;
		}
		if(a[i] == b[j]){
			--i, --j;
			continue ;
		}
		if(i == -1 || s.find(a[i]) == s.end()){
			pos = 0;
			break ;
		}
		s.erase(s.find(a[i]));
		--i;
	}
	if(pos)
		cout << "YES\n";
	else
		cout << "NO\n";
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