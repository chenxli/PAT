#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;
int main()
{
  map<string,int> map1;
  string s;
  getline(cin,s,'\n');
  int i = 0;
  string temp = "";
  while(i < s.size())
  {
    if(isalnum(s[i]))
    {
      temp += s[i];
    }
    else
    {
      if(temp != "")
      {
        for(int j = 0; j < temp.size(); j++)
        {
          if(isupper(temp[j]))
            temp[j] = tolower(temp[j]);
         }
        map1[temp]++;
        temp = "";
      }
    }
    i++;
  }
  if(temp != "")
  {
    for(int j = 0; j < temp.size(); j++)
    {
      if(isupper(temp[j]))
        temp[j] = tolower(temp[j]);
     }
    map1[temp]++;
    temp = "";
  }
  map<string,int>::iterator it = map1.begin();
  int max = -1;
  string tmp = "";
  for(;it != map1.end(); it++)
  {
    if(it->second > max || (it->second == max && it->first < tmp))
    {
      max = it->second;
      tmp = it->first;
    }
  }
   cout<<tmp<<" "<<max<<endl;
   return 0;
}
