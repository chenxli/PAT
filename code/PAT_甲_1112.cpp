#include <iostream>
#include <string>
using namespace std;
int main()
{
  int n;
  cin>>n;
  string s;
  cin>>s;
  int arr[37] = {0};//先0-9，-，最后11-36位a-z,
  int count = 1;
  for(int i = 1; i < s.size(); i++)
  {
    if(s[i] != s[i-1] && count % n != 0)
    {
      count = 1;
      if(s[i-1] == '_')
        arr[10] = 1;
      else if(s[i-1] >= '0' && s[i-1] <= '9')
        arr[s[i-1]-'0'] = 1;
      else
        arr[s[i-1]-'a'+11] = 1;
    }
    else if(s[i] != s[i-1])
      count = 1;
    else if(s[i] == s[i-1])
      count++;
  }
  if(count % n != 0)
  {
    char ch = s[s.size()-1];
    if(ch == '_')
      arr[10] = 1;
    else if(ch >= '0' && ch <= '9')
      arr[ch-'0'] = 1;
    else
      arr[ch-'a'+11] = 1;
  }
  string s1;
  for(int i = 0; i < s.size(); i++)
  {
    char ch = s[i];
    if(ch == '_')
    {
      if(!arr[10])
      {
        s.erase(i+1,n-1);
        if(s1.find('_') == -1)
          s1 += '_';
      }
    }
    else if(ch >= '0' && ch <= '9')
    {
      if(!arr[ch-'0'])
      {
        s.erase(i+1,n-1);
        if(s1.find(ch) == -1)
          s1 += ch;
      }
    }
    else
    {
      if(!arr[ch-'a'+11])
      {
        s.erase(i+1,n-1);
        if(s1.find(ch) == -1)
          s1 += ch;
      }
    }
  }
  cout<<s1<<endl;
  cout<<s<<endl;
  return 0;
}
