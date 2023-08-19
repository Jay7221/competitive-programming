#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e4;
const int maxT = 100;
const int maxA = 1e3;
const int maxB = 1e9;
const int maxH = 1;
#define ll long long
int testcaseNumber = 0;
void generate_testcase(){
	int n = (rand() % maxN) + 1;
	assert((n >= 1) && (n <= maxN));
	int a[n], b[n];
	for(int i = 0; i < n; ++i){
		a[i] = (rand() % maxA) + 1;
		b[i] = (rand() % maxB) + 1;
	}
	cout << n << '\n';
	for(int i = 0; i < n; ++i){
		cout << a[i] << ' ';
		assert((a[i] >= 1) && (a[i] <= maxA));
	}
	cout << '\n';
	for(int i = 0; i < n; ++i){
		cout << b[i] << ' ';
		assert((b[i] >= 1) && (b[i] <= maxB));
	}
	cout << '\n';
	int H = (rand() % maxH) + 1;
	assert((H >= 1) && (H <= maxH));
	cout << H << '\n';
	return ;
}
int main(int argc, char **argv){
	string file_path = "testcase0.txt";
	if(argc > 1){
		file_path[8] = argv[1][0];
	}
	freopen(file_path.c_str(), "w", stdout);
	srand(time(0));
	int t = (rand() % maxT) + 1;
	assert(t <= maxT);
	cout << t << '\n';
	while(t--){
		generate_testcase();
	}
	return 0;
}
