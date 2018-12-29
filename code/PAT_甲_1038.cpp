#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool cmp(string a,string b)
{
  int i;
  for(i = 0; i < a.size() && i < b.size(); i++)
  {
    if(a[i] != b[i])
     return a[i] < b[i];
  }
  if(a.size() < b.size())
    return a[0] < b[i];
  if(b.size() < a.size())
    return a[i] < b[0];
  if(a.size() == b.size())
    return true;
    //  return a + b < b + a;
}
int main()
{
  int n;
  cin>>n;
  vector<string> v(n);
  for(int i = 0; i < n; i++)
  {
    cin>>v[i];
  }
  sort(v.begin(),v.end(),cmp);
  string s;
  for(int i = 0; i < n; i++)
  {
    s += v[i];
  }
  bool zero = true;
  for(int i = 0; i < s.size(); i++)
  {
    if(s[i] != '0')
      zero = false;
    if(!zero)
      cout<<s[i];//s可能全为0,此时应该输出一个0
  }
  if(zero)
   cout<<0;
  cout<<endl;
  return 0;
}
