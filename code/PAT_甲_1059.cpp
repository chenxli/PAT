#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int isPrime(int n)
{
  for(int i = 2; i * i <= n; i++)
  {
    if(n % i == 0)
      return false;
  }
  return true;
}
int main()
{
  int num;
  cin>>num;
  map<int,int> MAP;
  int m = num;
  if(num == 1)
  {
    cout<<num<<"="<<1<<endl;
    return 0;
  }
  for(int i = 2; i <= m && num != 1; i++)
  {
    if(isPrime(i))
    {
      while(num % i == 0)
      {
        MAP[i]++;
        num /= i;
      }
    }
  }
  int size = MAP.size();
  int count = 0;
  map<int,int>::iterator it = MAP.begin();
  cout<<m<<"=";
  for(;it != MAP.end(); ++it)
  {
    count++;
    cout<<it->first;
    if(it->second > 1)
      cout<<"^"<<it->second;
    if(count < size)
      cout<<"*";
  }
  return 0;
}
