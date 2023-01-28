#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n), cnt(n + 1);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	ll sum = 0;
	// sum represents the cost required to get atleast 0 1 2 ... i - 1
	stack<ll> st;
	// st stores all the unnecessary smaller values which may be used in future
	// also all these values are in increasing order to ensure optimality
	vector<ll> ans(n + 1, -1);
	for(int i = 0; i < n + 1; i++){
		if(i > 0 && cnt[i - 1] == 0){
			if(st.empty())
				break ;
			// if the stack is empty then there are no values from which we may get i - 1
			// thus ther is no way to make i, i + 1, ... , n the MEX of the array 
			int j = st.top();
			st.pop();
			sum += i - 1 - j;
		}
		ans[i] = sum + cnt[i];
		// cnt[i] because we have to deal with the values i in the array and make them i + 1
		// which uses one operation
		if(i > 0){
			// here we push all the unused values of i - 1 into the stack for future use
			while(cnt[i - 1] > 1){
				cnt[i - 1]--;
				st.push(i - 1);
			}
		}
	}
	for(auto c : ans)
		cout << c << ' ' ;
	cout << '\n';
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