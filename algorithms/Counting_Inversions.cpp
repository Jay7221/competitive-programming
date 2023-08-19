#include<iostream>
#include<vector>
using namespace std;
const int INF = 1e9 + 7;
void print(vector<int> &a, int p, int q){
	for(int i = p; i <= q; ++i)
		cout << a[i] << ' ';
	cout << endl;
}
int binary_search(vector<int> &A, int val, int p, int q){
	int l = p - 1, r = q;
	while(l < r){
		int m = (l + r + 1) / 2;
		if(A[m] < val)
			l = m;
		else
			r = m - 1;
	}
	return (l - p + 1);
}
void merge(vector<int> &A, int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	// Merger two sorted arrays a[p..q] and a[q + 1 .. r]
	vector<int> L(n1 + 1), R(n2 + 1);
	for(int i = 0; i < n1; ++i)
		L[i] = A[i + p];
	for(int i = 0; i < n2; ++i)
		R[i] = A[i + q + 1];
	L[n1] = INF;
	R[n2] = INF;
	int i = 0, j = 0;
	for(int k = p; k <= r; ++k){
		if(L[i] <= R[j]){
			A[k] = L[i];
			++i;
		}
		else{
			A[k] = R[j];
			++j;
		}
	}
}
int count_inversions(vector<int> &A, int p, int q){
	if(p >= q)
		return 0;
	int m = (p + q) / 2;
	int ans = count_inversions(A, p, m) + count_inversions(A, m + 1, q);
	for(int i = p; i <= m; ++i){
		ans += binary_search(A, A[i], m + 1, q);
	}
	merge(A, p, m, q);
	return ans;
}
int main(){
	int n;
	cout << "Enter the number of elements : ";
	cin >> n;
	cout << "Enter the elements of the array : ";
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	cout << "The number of inversions in the array is : ";
	cout << count_inversions(a, 0, n - 1) << endl;
	return 0;
}
