#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  vector<long int> v;
  int n1,n2;
  cin>>n1;
  for(int i = 0; i < n1; i++)
  {
    long int tmp;
    scanf("%ld",&tmp);
    v.push_back(tmp);
  }
  cin>>n2;
  for(int i = 0; i < n2; i++)
  {
    long int tmp;
    scanf("%ld",&tmp);
    v.push_back(tmp);
  }
  sort(v.begin(),v.end());
  if(v.size() % 2)
    cout<<v[v.size() / 2]<<endl;
  else
    cout<<v[v.size() / 2 - 1]<<endl;
  return 0;
}
