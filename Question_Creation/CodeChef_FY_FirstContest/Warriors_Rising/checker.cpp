#include<bits/stdc++.h>
using namespace std;
void check(int testcaseNo)
{
    printf("----------------  Checking TestCase %d  ------------------------\n", testcaseNo);
    printf("----------------  Checking of TestCase %d Done  ----------------\n", testcaseNo);
}
int main(int argc, char **argv)
{
    ifstream testcaseIn, outputIn, expOutputIn;
    testcaseIn.open(argv[1]);
    outputIn.open(argv[2]);
    expOutputIn.open(argv[3]);
    int T;
    testcaseIn >> T;
    for(int testcase = 1; testcase <= T; ++testcase)
    {
        check(testcase);
    }
    return 0;
}