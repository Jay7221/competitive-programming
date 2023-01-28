#include<iostream>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int MAX = 200000;
  int a[MAX], b[MAX];
  for(int i = 0; i < MAX; ++i)
  {
    cin >> a[i];
  }
  for(int i = 0; i < MAX; ++i)
  {
    cin >> b[i];
  }
  for(int i = 0; i < MAX; ++i)
  {
    if(a[i] != b[i])
    {
      cout << i << ' ' << a[i] << ' ' << b[i] << "\n";
    }
  }
  return 0;
}