#include <iostream>
#include <string>
using namespace std;
int main()
{
  string s,s1;
  cin>>s;
  bool flag = false;
  bool zhi = false;
  if(s[0] == '-')
    flag = true;
  int index = s.find('E');
  if(s[index+1] == '+')
    zhi = true;
  int mi = 0;
  for(int i = index + 2; i < s.size(); i++)
  {
    mi = mi * 10 + (s[i] - '0');
  }
  if(zhi)
  {
    int point = s.find('.');
    s1 = s.substr(1,point - 1)+ s.substr(point + 1, index - point - 1);
    if(point + mi < index - 1)
      s1.insert(point+mi-1,".");
    else if(point + mi > index - 1)
      s1.append(point+mi-index+1,'0');
    int j = 0;
    while(s1[j] == '0' && s1[j+1] == '0')
    {
      j++;
    }
    s1 = s1.substr(j,s1.size()-j+1);
  }
  else
  {
    int point = s.find('.');
    s1 = s.substr(1,point-1) + s.substr(point + 1, index - point - 1);
    point = point - 1;
    if(point-mi > 0)
    {
      s1.insert(point-mi,".");
      int j = 0;
      while(s1[j] == '0' && s1[j+1] != '.')
         s1 = s1.substr(j+1,s1.size()-j-1);
    }
    else
    {
      for(int k = 0; k <= mi - point; k++)
        s1 = '0' + s1;
      s1.insert(1,".");
    }
  }
  if(flag)
   s1 = '-' + s1;
  cout<<s1<<endl;
  return 0;
}
