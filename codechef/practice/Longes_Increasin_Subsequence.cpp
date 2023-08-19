#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
int lis(vi a){
	int n = a.size();
	vi seq;
	vi size;
	seq.push_back(a[0]);
	for(int i = 1; i < n; i++){
		int k = lower_bound(seq.begin(), seq.end(), a[i]) - seq.begin();
		if(k < seq.size() && k >= 0)
			seq[k] = a[i];
		if(a[i] > seq[seq.size() - 1])
			seq.push_back(a[i]);
		if(a[i] < seq[0])
			seq.insert(a.begin(), a[i]);
	}
	return seq.size();
}
int main(){
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << lis(a) << '\n';
}