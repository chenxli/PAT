#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
string reverseStr(string s)
{
  string s1;
  for(int i = s.size() - 1; i >= 0; i--)
  {
    s1 += s[i];
  }
  return s1;
}
int main()
{
  int n;
  scanf("%d",&n);
  getchar();
  vector<string> str;
  int minLen = 1000;
  for(int i = 0; i < n; i++)
  {
    string s;
    getline(cin,s,'\n');
    if(minLen > s.size())
      minLen = s.size();
    str.push_back(reverseStr(s));
  }
  string res;
  bool flag = true;
  int k = 0;
  while(k < minLen)
  {
    char ch = str[0][k];
    for(int i = 1; i < n; i++)
    {
      if(str[i][k] != ch)//数组访问过界
      {
        flag = false;
        break;
      }
    }
    if(flag)
    {
      res += ch;
      k++;
    }
    else
     break;
  }
  if(res.size() == 0)
    printf("nai\n");
  else
    cout<<reverseStr(res)<<endl;
  return 0;
}
