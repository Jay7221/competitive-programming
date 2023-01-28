#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5;
const int maxK = 1e5;
const int maxA = 1e5;
const int minK = 1;
const int minN = 1e3;
const int minA = 0;
const int diffN = maxN - minN;
const int diffK = maxK - minK;
const int diffA = maxA - minA;
#define ll long long
int testcaseNumber = 0;
void generate_testcase(){
	int dum1 = rand(), dum2 =rand(), dum3 = rand();
	cout << dum1 << '\n' << dum2 << '\n' << dum3 << '\n';
	int k = (rand() % diffK) + minK;
	int n = (rand() % diffN) + minN;
	k = (k % n) + 1;
	assert((n >= minN) && (n <= maxN));
	assert((k >= 1) && (k <= n));
	int a[n];
	for(int i = 0; i < n; ++i){
		a[i] = (rand() % diffA) + minA;
		assert((a[i] >= minA) && (a[i] <= maxA));
	}
	cout << k << '\n';
	cout << n << '\n';
	for(int i = 0; i < n;++i){
		cout << a[i] << '\n';
	}
}
int main(int argc, char **argv){
	string file_path = "testcase0.txt";
	if(argc > 1){
		file_path[8] = argv[1][0];
	}
	freopen(file_path.c_str(), "w", stdout);
	srand(time(0));
	generate_testcase();
	return 0;
}
