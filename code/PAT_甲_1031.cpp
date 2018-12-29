#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int x,y,size = s.size();
  for(int i = (size - 1) / 2; i > 0; i--)
  {
    x = i;
    y = size + 2 - 2 * x;
    if(x <= y)
     break;
  }
  for(int i = 0; i < x - 1; i++)
  {
    cout<<s[i];
    for(int j = 0; j < y - 2; j++)
     cout<<" ";
    cout<<s[size - 1 - i]<<endl;
  }
  for(int i = x - 1; i < x + y - 1; i++)
  {
    cout<<s[i];
  }
  cout<<endl;
  return 0;
}
