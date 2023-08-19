#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define ff fflush(stdin);	fflush(stdout);
char query1(int i){
	++i;
	ff
	printf("? 1 %d\n", i);
	ff
	char ans;
	scanf("%c", &ans);
	ff
	return ans;
}
int query2(int i, int j){
	++i, ++j;
	ff 
	printf("? 2 %d %d\n", i, j);
	ff
	int ans;
	scanf("%d", &ans);
	ff
	return ans;
}
void solve(){
	int n;
	cin >> n;
	ff
	vector<char> s(n);
	vector<int> c;
	for(int i = 0; i < n; ++i){
		sort(c.rbegin(), c.rend());
		if(c.size() && query2(c.back(), i) == c.size()){
			int l = 0, r = c.size() - 1;
			while(l < r){
				int mid = (l + r) / 2;
				if(query2(c[mid], i) == mid + 1){
					r = mid;
				}else{
					l = mid + 1;
				}
			}
			s[i] = s[c[l]];
			c[l] = i;
		}
		else{
			s[i] = query1(i);
			c.push_back(i);
		}
	}
	ff
	cout << "! ";
	for(int i = 0; i < n; ++i)
		cout << s[i] ;
	cout << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}