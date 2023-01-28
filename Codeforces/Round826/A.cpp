#include<iostream>
using namespace std;
int cmp(string& a, string& b){
	// Returns true if a > b
	if(a == b)
		return false;
	int n1 = a.size(), n2 = b.size();
	if(a[n1 - 1] != b[n2 - 1]){
		if(a[n1 - 1] == 'S')
			return false;
		if(b[n2 - 1] == 'L')
			return false;
		return true;
	}else{
		if(a[n1 - 1] == 'S'){
			if(n1 > n2)
				return false;
			else
				return true;
		}else{
			if(n1 < n2)
				return false;
			else
				return true;
		}
	}

}
void solve(){
	string a, b;
	cin >> a >> b;
	if(cmp(a, b))
		cout << ">\n";
	else if(cmp(b, a))
		cout << "<\n";
	else
		cout << "=\n";
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}