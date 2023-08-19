#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	auto square = [&](int a){
		return  a * a;
	};
	cout << square(3) << '\n';
	return 0;
}