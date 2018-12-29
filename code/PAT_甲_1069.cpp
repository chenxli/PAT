#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int m = n;
  vector<int> v(4,0);
  for(int i = 0; i < 4; i++)
  {
    v[i] = m % 10;
    m /= 10;
  }
  sort(v.begin(),v.end());
  int A = 0,B = 0;
  for(int i = 3; i >= 0; i--)
  {
    A = A * 10 + v[i];
  }
  for(int i = 0; i < 4; i++)
  {
    B = B * 10 + v[i];
  }
  if(A - B == 0)
  {
    printf("%04d - %04d = 0000\n",A,B);
    return 0;
  }
  int res = -1;
  while(A - B != res)
  {
    printf("%04d - %04d = %04d\n",A,B,A-B);
    res = A - B;
    A = B = 0;
    m = res;
    for(int i = 0; i < 4; i++)
    {
      v[i] = m % 10;
      m /= 10;
    }
    sort(v.begin(),v.end());
    for(int i = 3; i >= 0; i--)
    {
      A = A * 10 + v[i];
    }
    for(int i = 0; i < 4; i++)
    {
      B = B * 10 + v[i];
    }
  }
  return 0;
}
