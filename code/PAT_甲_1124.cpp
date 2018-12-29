#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
  int m,n,s;
  scanf("%d%d%d",&m,&n,&s);
  vector<string> follower;
  map<string,int> mm;
  int k = 0;
  for(int i = 0; i < m; i++)
  {
    string name;
    cin>>name;
    mm[name] = 0;
    follower.push_back(name);
  }
  if(s > m)
  {
    printf("Keep going...\n");
    return 0;
  }
  else
  {
    for(int i = s - 1; i < follower.size(); i += n)
    {
      string name = follower[i];
      if(mm[name] == 0)
      {
        cout<<name<<endl;
        mm[name] = 1;
      }
      else
      {
        while(mm[follower[i]] == 1 && i < follower.size())
        {
          i++;  
        }
        if(i < follower.size())
        {
          mm[follower[i]] = 1;
          cout<<follower[i]<<endl;
        }
      }
    }
  }
  return 0;
}
