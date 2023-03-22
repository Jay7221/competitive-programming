#include<bits/stdc++.h>
using namespace std;
#define ll long long
template<typename T>
void print(T &arr){
	for(char elem : arr){
		cerr << elem << ' ' ;
	}
	cerr << '\n';
}
void solve(){
	string a;
	cin >> a;
	int n = a.size();
	multiset<char> m;
	for(char ch : a){
		m.insert(ch);
	}
	auto front = [&](){
		return (*m.begin());
	};
	auto pop = [&](){
		m.erase(m.begin());
	};
	int l = 0, r = n - 1;
	while(l <= r){
		if(l == r){
			a[r] = front();
			pop();
		}else{
			a[r] = front();
			pop();
			a[l] = front();
			pop();
			if(m.size() && (front() == a[l])){
				char tmp = a[r];
				a[r] = front();
				pop();
				m.insert(tmp);
			}
		}
		++l;
		--r;
	}
	cout << a << '\n';
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

	return 0;
}
