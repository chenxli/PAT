#include <iostream>
#include <algorithm>
#include <vector>
#define max(a,b) a>b?a:b
using namespace std;
int main()
{
  int N;
  long long p;
  cin>>N>>p;
  vector<long long> v;
  for(int i = 0; i < N; i++)
  {
    long long value;
    cin>>value;
    v.push_back(value);
  }
  sort(v.begin(),v.end());
  int maxNum = 0;
  int i = 0,j = 0;
  while(i < N && j < N)
  {
    while(j < N && v[j] <= p * v[i])
    {
      maxNum = max(maxNum,j - i + 1);
      j++;
    }
    i++;
  }
 cout<<maxNum<<endl;
  return 0;
}
