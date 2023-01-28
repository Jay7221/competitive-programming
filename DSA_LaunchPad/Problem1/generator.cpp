#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e4;
const int maxT = 100;
const int maxQ = 1e3;
const int maxE = 1e9;
int testcaseNumber = 0;
void generate_testcase(){
	int n = (rand() % maxN) + 1;
	assert(n <= maxN);
	int q = (rand() % maxQ) + 1;
	assert(q <= maxQ);
	int efforts[n], query[q];
	for(int i = 0; i < n; ++i){
		efforts[i] = (rand() % maxE) + 1;
		assert(efforts[i] <= maxE);
	}
	for(int i = 0; i < q; ++i){
		query[i] = (rand() % maxE) + 1;
		assert(query[i] <= maxE);
	}
	cout << n << '\n';
	for(int i = 0; i < n; ++i)
		cout << efforts[i] << ' ';
	cout << '\n';
	cout << q << '\n';
	for(int i = 0; i < q; ++i){
		cout << query[i] << '\n';
	}
	return ;
}
int main(int argc, char **argv){
	string file_path = "testcase";
	if(argc > 1){
		testcaseNumber = argv[1][0] - '0';
	}
	file_path.push_back('0' + testcaseNumber);
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
