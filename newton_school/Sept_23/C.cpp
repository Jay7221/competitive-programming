#include <iostream>
using namespace std;
 
int main() {
  int tc;
  cin >> tc;
  for(int t = 1; t <= tc; ++t){
    int n, m;
    cin >> n >> m;
    if(m == 0){
      cout << "A";
      continue;
    }
    int no_stacks = (n + m - 1) / m;
    int no_turns = n - no_stacks;
    if(no_turns % 2 == 1){
      cout << "A";
    }
    else{
      cout << "B";
    }
  }
    
    return 0;
}
 
