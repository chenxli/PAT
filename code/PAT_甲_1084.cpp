#include <iostream>
#include <string>
using namespace std;
int main()
{
  string s1,s2;
  cin>>s1>>s2;
  string res;
  for(int i = 0; i < s1.size(); i++)
  {
    if(s2.find(s1[i]) == string::npos)
    {
      char ch = s1[i];
      if(s1[i] >= 'a' && s1[i] <= 'z')
        ch =  static_cast<char>(s1[i] - 'a' + 'A');
      if(res.find(ch) == string::npos)
      {
          res = res + ch;
      }
    }
  }
  cout<<res<<endl;
  return 0;
}
