#include <iostream>
#include <string>
using namespace std;
int main()
{
  string s;
  getline(cin,s,'\n');
  int len = 1;
  int max = 1;
  for(int i = 1; i < s.size() - 1; i++)
  {
    len = 1;
    for(int j = 1; i - j >= 0 && i + j < s.size(); j++)
    {
      if(s[i-j] == s[i+j])
      {
        len += 2;
        if(len > max)
          max = len;
      }
      else break;
    }
    if(s[i-1] == s[i])
    {
      len = 2;
      for(int j = 1; i - 1 - j >=0 && i + j < s.size(); j++)
      {
        if(s[i-1-j] == s[i + j])
        {
          len+=2;
          if(len > max) max = len;
        }
        else
        break;
      }
    }
    else if(s[i]==s[i+1])
    {
      len = 2;
      for(int j = 1; i - j >=0 && i + 1 + j < s.size(); j++)
      {
        if(s[i - j] == s[i + 1 + j])
          {
            len += 2;
            if(len > max) max = len;
          }
        else
          break;
      }
    }
  }
  cout<<max<<endl;
  return 0;
}
